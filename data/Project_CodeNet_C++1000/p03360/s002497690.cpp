#include <bits/stdc++.h>
#define fastIO (cin.tie(0), cout.tie(0), ios::sync_with_stdio(false))
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define precise(i) fixed << setprecision(i)
using lint = long;
using llint = long long;
using namespace std;

int main() {
    fastIO;
    vector<int> nums(3);
    rep(i, 3) cin >> nums.at(i);
    sort(nums.begin(), nums.end());

    int k;
    cin >> k;
    rep(i, k) nums.at(2) *= 2;
    cout << nums.at(0) + nums.at(1) + nums.at(2) << endl;
}
