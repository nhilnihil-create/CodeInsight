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
    ll n, a[17][17], dp[66000]={0}, pc, sc[66000]={0};
    cin >> n;
    rep(i,0,n-1){
    	rep(j,0,n-1){
    		cin >> a[i][j];
    	}
    }
    rep(bit,1,(1<<n)-1){
    	ll pc = __builtin_popcountll(bit);
    	vc st;
    	rep(i,0,n-1) if(bit&(1<<i)) st.pb(i);
    	rep(i,0,pc-1){
    		rep(j,i+1,pc-1){
    			sc[bit] += a[st[i]][st[j]];
    		}
    	}
    	dp[bit] = sc[bit];
    	for(ll b3=(bit-1)&bit;b3>0;b3=(b3-1)&bit){
    		chmax(dp[bit], dp[bit-b3] + sc[b3]);
    	}
    }
    cout << dp[(1<<n)-1] << endl;
    return 0;
}