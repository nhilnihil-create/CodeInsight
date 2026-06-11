#include <bits/stdc++.h>

#define rep(l, r) for (int i = (l); i < (r); i++)

typedef long long ll;
 
using namespace std;

int main() {
    int nums[3];
    rep(0, 3) cin >> nums[i];

    sort(nums, nums + 3);

    cout << (nums[0] == nums[1] ? nums[2] : nums[0]) << endl;

    return 0;
}
