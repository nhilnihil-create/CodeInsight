#include <bits/stdc++.h>
using namespace::std;

#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef array<int, 3> tri;
typedef long double ld;

template <class T> istream& operator>>(istream& I, vector<T>& v) {for (T &e: v) I >> e; return I;}
template <class T> ostream& operator<<(ostream &O, const vector<T>& v) {for (const T &e: v) O << e << ' '; return O;}


const int mod = 1e9 + 7;
void _main() {
        int n; cin >> n;
        vector<vector<int>> match(n, vector<int>(n));
        for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                        cin >> match[i][j];
                }
        }

        vector<int> dp(1 << n);
        dp[0] = 1;
        for (int man = 0; man < n; man++) {
                vector<int> new_dp(1 << n);
                for (int mask = 0; mask < (1 << n); mask++) {
                        if (__builtin_popcount(mask) != man + 1) continue;
                        for (int woman = 0; woman < n; woman++) {
                                if (1 << woman & mask && match[man][woman]) {
                                        (new_dp[mask] += dp[mask ^ (1 << woman)]) %= mod;
                                }
                        }
                }
                dp = new_dp;
        }

        cout << dp.back();
}



signed main() {
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//        freopen("input.txt", "r", stdin);
        int _t = 1;
//        cin >> _t;
        while (_t--) _main();
        return 0;
}