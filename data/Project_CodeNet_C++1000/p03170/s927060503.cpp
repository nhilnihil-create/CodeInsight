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

ll n, k;
vector<ll> a, dp;

void dfs(ll v) {
    if (dp[v] != -1) return;
    bool f = false;
    rep(i, n) {
        ll nv = v - a[i];
        if (nv < 0) continue;
        dfs(nv);
        if (dp[nv] == 0) {
            f = true;
        }
    }
    dp[v] = f ? 1 : 0;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    // ifstream in("input.txt");
    // cin.rdbuf(in.rdbuf());
    cin >> n >> k;
    a.resize(n);
    rep(i, n) cin >> a[i];
    dp.resize(k + 1, -1);
    dp[0] = 0;
    dfs(k);
    cout << ((dp[k] == 1) ? "First" : "Second") << endl;
    return 0;
}
