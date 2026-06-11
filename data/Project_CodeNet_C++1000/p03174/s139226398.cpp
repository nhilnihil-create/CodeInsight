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
using namespace std;
typedef long long ll;
ll q, dp[25][(1 << 21) + 5], a[55][55] , b[555555], k, l, m, n, o, p;
map < ll , ll > mp;
vll adj[555555];
const ll mod = 1e9+7;
ll mem(ll i , ll mask){
	if(i == n){
		return 1;
	}
	ll &r = dp[i][mask];
	if(r != -1)return r;
	r = 0;
	for(ll j = 0 ; j < n ; j++){
		if((mask & (1 << j))) continue;
		if(a[i][j]){
			r = (r + mem(i + 1 , mask | (1 << j))) % mod; 
		}
	}
	return r;
}
void solve(){
	memset(dp , -1 , sizeof dp);
	cin >> n;
	for(ll i = 0 ; i < n ; i++){
		for(ll j = 0 ; j < n ; j++){
			cin >> a[i][j];
		}
	}
	cout << mem(0,0) << endl;
}
int main() {
    fast ;
	// cin >> q;
    q = 1;
    while(q--){
    	solve();
	}
}