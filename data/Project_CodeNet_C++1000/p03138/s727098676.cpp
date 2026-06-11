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

string f(ll v) {
    string ans = "";
    while(v) {
        ans += (char)(v % 2 + '0');
        v /= 2;
    }
    reverse(all(ans));
    return ans;
}

string g(string s, ll k) {
    ll r = k - len(s);
    string p = "";
    rep(i, r) p += '0';
    return p + s;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    // ifstream in("input.txt");
    // cin.rdbuf(in.rdbuf());
    const ll inf = LONG_LONG_MIN / 2 + 1;
    const ll MB = 41;
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    vector<ll> bc(MB, 0);
    rep(i, n) {
        rep(j, MB) {
            if (a[i] & (1LL << j)) bc[j]++;
        }
    }
    string kb = g(f(k), MB);
    ll nn = len(kb);
    // dp[figure][0:just, 1:smaller]
    vector<vector<ll>> dp(nn + 1, vector<ll>(2, inf));
    dp[0][0] = 0;
    rep(i, nn) {
        ll cv = kb[i] - '0';
        if (cv == 0) {
            if (dp[i][0] != inf) {
                chmax(dp[i + 1][0], dp[i][0] * 2 + bc[nn - 1 - i]);
            }
            if (dp[i][1] != inf) {
                chmax(dp[i + 1][1], dp[i][1] * 2 + bc[nn - 1 - i]);
                chmax(dp[i + 1][1], dp[i][1] * 2 + (n - bc[nn - 1 - i]));
            }
        }
        else {
            if (dp[i][0] != inf) {
                chmax(dp[i + 1][0], dp[i][0] * 2 + (n - bc[nn - 1 - i]));
                chmax(dp[i + 1][1], dp[i][0] * 2 + bc[nn - 1 - i]);
            }
            if (dp[i][1] != inf) {
                chmax(dp[i + 1][1], dp[i][1] * 2 + bc[nn - 1 - i]);
                chmax(dp[i + 1][1], dp[i][1] * 2 + (n - bc[nn - 1 - i]));
            }
        }
    }
    ll ans = max(dp[nn][0], dp[nn][1]);
    ll tmp = 0;
    rep(i, n) tmp += 0 ^ a[i];
    chmax(ans, tmp);
    cout << ans << endl;
    return 0;
}
