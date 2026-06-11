#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(ll i = 0, i##_len = (n); i < i##_len; i++)
#define reps(i, s, n) for(ll i = (s), i##_len = (n); i < i##_len; i++)
#define rrep(i, n) for(ll i = (n) - 1; i >= 0; i--)
#define rreps(i, e, n) for(ll i = (n) - 1; i >= (e); i--)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) ((ll)(x).size())
#define len(x) ((ll)(x).length())
#define endl "\n"
template<class T> void chmax(T &a, const T b){ a = max(a, b); }
template<class T> void chmin(T &a, const T b){ a = min(a, b); }

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    // ifstream in("input.txt");
    // cin.rdbuf(in.rdbuf());
    const ll inf = LONG_LONG_MIN / 2 - 1;
    ll n;
    cin >> n;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    vector<vector<ll>> dp(n + 1, vector<ll>(2, inf));
    dp[0][0] = 0;
    rep(i, n) {
        {
            chmax(dp[i + 1][0], dp[i][0] + a[i]);
            chmax(dp[i + 1][0], dp[i][1] - a[i]);
        }
        if (i < (n - 1)) {
            chmax(dp[i + 1][1], dp[i][0] - a[i]);
            chmax(dp[i + 1][1], dp[i][1] + a[i]);
        }
    }
    cout << dp[n][0] << endl;
    return 0;
}
