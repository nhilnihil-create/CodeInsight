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
ll q, dp[405][405], a[555555] , b[555555], k, m, n, o, p;
map < ll , ll > mp;
vll adj[555555];
const ll mod = 1e9+7;
ll mem(ll l , ll r){
	if(l == r)return 0;
	ll &ret = dp[l][r];
	if(ret != -1)return ret;
	ret = 1e18;
	for(ll i = l ; i < r ; i++){
		ret = min( ret , a[r] - a[l - 1] + mem(l , i) + mem(i + 1 , r));
	}
	return ret;
}
void solve(){
	msdp(dp);
	cin >> n;
	for(ll i = 1 ; i <= n ; i++){
		cin >> a[i];
		a[i] += a[i - 1];
	}
	cout << mem(1 , n) << endl;
}
int main() {
    fast ;
	// cin >> q;
    q = 1;
    while(q--){
    	solve();
	}
}

