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

int main() {
    // your code goes here
    ll n, dp[3005][3005]={0}, sa[3005][3005]={0}, sb[3005][3005]={0};
    string s;
    cin >> n >> s;
    dp[0][1] = 1;
    sa[0][1] = 1;
    sb[0][1] = 1;
    rep(i,1,n-1){
    	rep(j,1,i+1){
    		if(s[i-1] == '<') dp[i][j] = sa[i-1][j-1];
    		else dp[i][j] = sb[i-1][j];
    	}
    	rep(j,1,i+1) sa[i][j] = (sa[i][j-1] + dp[i][j]) % mod;
    	repr(j,i+1,1) sb[i][j] = (sb[i][j+1] + dp[i][j]) % mod;
    }
    cout << sa[n-1][n] << endl;
    return 0;
}