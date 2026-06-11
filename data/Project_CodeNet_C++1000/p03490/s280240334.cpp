#include <iostream>
#include <vector>
#include <list>
using namespace std;

int main() {
    string s;
    int x, y, j = 0, k = 0;
    cin >> s >> x >> y;
    list<int> nums[2];
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'T') {
            nums[j].emplace_back(k);
            k = 0;
            j = 1 - j;
        } else {
            k++;
        }
    }
    nums[j].emplace_back(k);
    x -= nums[0].front();
    nums[0].pop_front();
    auto knapsack = [&](list<int>& nums, int target)->bool {
        int size = s.size() * 2 + 1;
        if (s.size() + target >= size) {
            return false;
        }
        vector<bool> table(size);
        auto dp = [&](int i) {
            return table[s.size() + i];
        };
        dp(0) = true;
        for (int i : nums) {
            vector<bool> next(size);
            for (int j = 0; j < size; j++) {
                if (j - i >= 0) {
                    next[j] = next[j] || table[j - i];
                }
                if (j + i < size) {
                    next[j] = next[j] || table[j + i];
                }
            }
            table = move(next);
        }
        return dp(target);
    };
    if (knapsack(nums[0], x) && knapsack(nums[1], y)) {
        cout << "Yes";
    } else {
        cout << "No";
    }
    return 0;
}
