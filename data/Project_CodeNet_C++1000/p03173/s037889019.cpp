#pragma GCC target("avx2")
#pragma GCC optimize("03")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std; typedef long double ld; typedef long long ll;
typedef unsigned long long ull;
#define endl "\n"
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define rep(i,n) for(int i=0;i<(n);i++)
#define PII pair<int, int>
#define PLL pair<ll, ll>
#define ALL(x) (x).begin(), (x).end()
constexpr int INF=1<<30; constexpr ll LINF=1LL<<60; constexpr ll mod=1e9+7; constexpr int NIL = -1;
template<class T>inline bool chmax(T &a, const T &b) { if (a<b) { a = b; return 1; } return 0; }
template<class T>inline bool chmin(T &a, const T &b) { if (b<a) { a = b; return 1; } return 0; }
//-------------------
constexpr int MX = 405;
vector<ll> a(MX);
vector<vector<ll>> dp(MX, vector<ll>(MX, LINF));
vector<ll> cum(MX);

ll dfs(int l, int r) {
    if(dp[l][r]!=LINF) return dp[l][r];
    ll res = LINF;
    for(int i=l; i<r; i++) {
        chmin(res, dfs(l, i)+dfs(i+1,r)+cum[r]-cum[l]+a[l]);
    }
    return dp[l][r] = res;
}

int main(){
    cin.tie(0); ios::sync_with_stdio(false); //cout << fixed << setprecision(15);
    int n; cin >> n;
    rep(i,n) cin >> a[i];
    cum[0] = a[0];
    FOR(i,1,n-1) {
        cum[i] = cum[i-1] + a[i];
    }
    rep(i,n) {
        dp[i][i] = 0;
        // if(i < n-1) dp[i][i+1] = a[i] + a[i+1];
    }   
    cout << dfs(0, n-1) << endl;
    return 0;
}
