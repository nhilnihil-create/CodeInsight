#include <bits//stdc++.h>
using namespace std;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
typedef long long int ll;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
vector<ll> a; vector<vector<ll>> dp;
ll rec(int l, int r) {
    if (l == r)return 0;
    if (dp[l][r] != -1)return dp[l][r];
    ll ret = 1e18;
    for (int i = l; i < r; i++) {
        chmin(ret, rec(l, i)+rec(i+1, r)+a[r] -a[l-1]);
    }return dp[l][r] = ret;
}
int main(void) {
    int n; cin >> n; a.resize(n+1,0); dp.resize(n+1, vector<ll>(n+1, -1));
    rep(i, n) cin >> a[i+1];
    rep(i, n) a[i + 1] += a[i];
    cout << rec(1, n) << endl;
}