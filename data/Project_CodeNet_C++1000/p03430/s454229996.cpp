#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; (i) < int(n); ++ (i))
#define REP3(i, m, n) for (int i = (m); (i) < int(n); ++ (i))
using namespace std;
template <class T> inline void chmax(T & a, T const & b) { a = max(a, b); }
template <typename X, typename T> auto vectors(X x, T a) { return vector<T>(x, a); }
template <typename X, typename Y, typename Z, typename... Zs> auto vectors(X x, Y y, Z z, Zs... zs) { auto cont = vectors(y, z, zs...); return vector<decltype(cont)>(x, cont); }

int solve(string const & s, int k) {
    int n = s.length();
    auto dp = vectors(n + 1, n + 1, k + 1, int());
    REP (l, n) {
        REP (i, k + 1) {
            dp[l][l + 1][i] = 1;
        }
    }
    REP3 (len, 2, n + 1) {
        REP (l, n - len + 1) {
            int r = l + len;
            REP (i, k + 1) {
                int & it = dp[l][r][i];
                if (s[l] == s[r - 1]) {
                    chmax(it, dp[l + 1][r - 1][i] + 2);
                }
                if (i - 1 >= 0) {
                    chmax(it, dp[l + 1][r - 1][i - 1] + 2);
                }
                chmax(it, dp[l + 1][r][i]);
                chmax(it, dp[l][r - 1][i]);
                if (i - 1 >= 0) {
                    chmax(it, dp[l][r][i - 1]);
                }
            }
        }
    }
    return dp[0][n][k];
}

int main() {
    string s; cin >> s;
    int k; cin >> k;
    cout << solve(s, k) << endl;
    return 0;
}
