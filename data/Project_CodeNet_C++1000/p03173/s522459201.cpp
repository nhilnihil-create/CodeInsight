#include <bits/stdc++.h>
// #include <atcoder/all>
using namespace std;
// using namespace atcoder;
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

const ll inf = LONG_LONG_MAX / 2 - 1;
ll n;
vector<ll> a;
vector<vector<pair<ll, ll>>> dp;

pair<ll, ll> dfs(ll l, ll r) {
    if (l == r) return dp[l][r] = make_pair(0, a[l]);
    pair<ll, ll> ans = dp[l][r];
    if (ans.first != inf) return ans;
    reps(i, l + 1, r + 1) {
        pair<ll, ll> lp = dfs(l, i - 1);
        pair<ll, ll> rp = dfs(i, r);
        ll val = lp.second + rp.second;
        ll sum = lp.first + rp.first + val;
        chmin(ans, make_pair(sum, val));
    }
    return dp[l][r] = ans;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    // ifstream in("input.txt");
    // cin.rdbuf(in.rdbuf());
    cin >> n;
    a.resize(n);
    rep(i, n) cin >> a[i];
    dp.resize(n, vector<pair<ll, ll>>(n, make_pair(inf, inf)));
    cout << dfs(0, n - 1).first << endl;
    return 0;
}
