#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>
#include <fstream>
#include <iterator>
#include <algorithm>

using namespace std;

class Solution {
    public:
        void nextPermutation(vector<int>& nums) {
            int sz = nums.size();
            int i = sz - 1;
            while (i >= 1 && nums[i] <= nums[i-1]) {
                i--;
            }
            if (i == 0) {
                reverse(begin(nums), end(nums));
            } else {
                auto min = nums[i - 1];
                auto max = nums[i];
                int loc = i, j;
                
                for (j = i; j <= sz - 1; ++j) {
                    if (nums[j] <= max) {
                        max = nums[j];
                    }
                    if (nums[j] > min && nums[j] <= max) {
                        loc = j;
                    }
                }
                swap(nums[i-1], nums[loc]);
                auto b = nums.begin();
                advance(b, i);
                sort(b, nums.end());
            }
        }
};

int main() {
    int tc;
    stringstream ss;
    string line;
    ifstream fin("next-perm.txt");

    getline(fin, line);
    ss << line;
    ss >> tc;
    ss.clear();

    for (int i = 0; i < tc; ++i) {
        getline(fin, line);
        ss << line;
        vector<int> numbers(istream_iterator<int>(ss), {});
        ss.clear();

        Solution().nextPermutation(numbers);        
    }

}
