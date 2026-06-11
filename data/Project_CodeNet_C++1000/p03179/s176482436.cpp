#include <bits/stdc++.h>
#define FOR(i, a, n) for(ll i = (ll)a; i < (ll)n; i++)
#define rep(i, n) FOR(i, 0, n)
#define ALL(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;

constexpr int mod = 1e9 + 7;

template <class T> inline bool chmax(T &a, const T &b) {
    if(a >= b) return false;
    a = b;
    return true;
}
template <class T> inline bool chmin(T &a, const T &b) {
    if(a <= b) return false;
    a = b;
    return true;
}

/*-------------------------------------------*/

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;
    string s;
    cin >> n >> s;

    int dp[2][3000] = {};
    rep(j, n) dp[0][j] = 1;
    FOR(i, 1, n) {
        if(s[i - 1] == '<') {
            dp[i & 1][n - 1 - i] = dp[i + 1 & 1][n - i];
            for(int j = n - 1 - i; j > 0; j--)
                dp[i & 1][j - 1] = (dp[i & 1][j] + dp[i + 1 & 1][j]) % mod;
        } else {
            dp[i & 1][0] = dp[i + 1 & 1][0];
            rep(j, n - 1 - i) dp[i & 1][j + 1] =
                (dp[i & 1][j] + dp[i + 1 & 1][j + 1]) % mod;
        }
    }

    cout << dp[n + 1 & 1][0] << endl;

    return 0;
}