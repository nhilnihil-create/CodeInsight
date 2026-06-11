#include <bits/stdc++.h>
using namespace std;
#pragma GCC target("avx")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
typedef long long ll;
typedef pair<ll,ll> pr;
typedef vector<ll> vc;
typedef unordered_map<ll,ll> umap;
#define pb emplace_back
#define rep(i,a,b) for(ll i=a;i<=b;i++)
#define repr(i,a,b) for(ll i=a;i>=b;i--)
#define reps(i,v) for(ll i=0;i<v.size();i++)
template<typename T> void chmin(T &a, const T &b) { a = min(a, b); }
template<typename T> void chmax(T &a, const T &b) { a = max(a, b); }
const ll mod = 1e9+7;
const ll max_n = 1e3+5;

int main() {
    // your code goes here
    ll n, w[max_n], s[max_n], v[max_n];
    ll dp[max_n][30050] = {0}, ans = 0;
    pair<pr,ll> tk[max_n];
    cin >> n;
    rep(i,0,n-1){
    	cin >> w[i] >> s[i] >> v[i];
    	tk[i] = {{w[i]+s[i],w[i]},v[i]};
    }
    sort(tk,tk+n);
    rep(i,1,n){
    	w[i] = tk[i-1].first.second;
    	s[i] = tk[i-1].first.first - w[i];
    	v[i] = tk[i-1].second;
    }
    rep(i,1,n){
    	rep(j,0,20000) dp[i][j] = dp[i-1][j];
    	rep(j,0,20000){
    		if(s[i]>=j) chmax(dp[i][w[i]+j], dp[i-1][j]+v[i]);
    	}
    }
    rep(i,0,20000) chmax(ans,dp[n][i]);
    cout << ans << endl;
    return 0;
}