#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int x; cin >>x;
    vector<int> nums;
    nums.push_back(1); // 1は何乗しても1だから
    for (int i = 2; i <= 31; i++) {
        int tmp = i;
        while (tmp*i<=1000) {
            nums.push_back(tmp*i);
            tmp *= i;
        }
    }
    sort(nums.begin(), nums.end());
    int ret = 1;
    for (auto i: nums) {
        if (i>x) {break;} else {ret=i;}
    }
    cout << ret << endl;
    return 0;
}