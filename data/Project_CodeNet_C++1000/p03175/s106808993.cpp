///apigs property
#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0)
#define F first
#define S second
#define pb push_back
#define vll vector< ll >
#define vi vector< int >
#define pll pair< ll , ll >
#define pi pair< int , int >
#define all(s) s.begin() , s.end()
#define sz(s) s.size()
#define md (s + e) / 2
#define mid (l + r) / 2
#define msdp(dp) memset(dp , -1 , sizeof dp)
#define mscl(dp) memset(dp , 0 , sizeof dp)
using namespace std;
typedef long long ll;
ll q, a[555555] , b[555555], k, l, m, n, o, p;
ll dp[100005][5];
vll adj[555555];
const ll mod = 1e9+7;
ll mem(ll i , ll oo, bool pp){
	ll &r = dp[i][pp];
	if(r != -1)return r;
	ll o1 = 1 , o2 = 1;
	if(!pp){
		for(auto u : adj[i]){
			if(u != oo){
				o1 = (o1 * mem(u , i , 0)) % mod;
				o2 = (o2 * mem(u , i , 1)) % mod;
			}
		}
		r = (o1 + o2) % mod;
	}
	else{
		for(auto u : adj[i]){
			if(u != oo){
				o1 = (o1 * mem(u , i , 0)) % mod;
			}
		}
		r = o1;
	}
	return r;
}
void solve(){
	msdp(dp);
	cin >> n;
	for(ll i = 0 ; i < n - 1 ; i++){
		cin >> o >> p;
		adj[o].pb(p);
		adj[p].pb(o);
	}
	cout << mem(1 , -1 , 0);
}
int main() {
    fast ;
	// cin >> q;
    q = 1;
    while(q--){
    	solve();
	}
}

