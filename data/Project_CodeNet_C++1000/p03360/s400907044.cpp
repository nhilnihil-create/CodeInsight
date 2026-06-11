#include <bits/stdc++.h>

#define rep(l, r) for (int i = (l); i < (r); i++)

typedef long long ll;
 
using namespace std;

void solve() {
    int a, b, c, k;
    cin >> a >> b >> c >> k;

    int nums[] = {a, b, c};
    sort(nums, nums+3);

    rep(0, k) nums[2] *= 2;

    int sum = 0;
    rep(0, 3) sum += nums[i];

    cout << sum << endl;
}

int main() {
    solve();

    return 0;
}
