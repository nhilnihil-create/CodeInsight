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
ll q, dp[100005], a[555555] , b[555555], k, l, m, n, o, p;
map < ll , ll > mp;
vll adj[555555];
const ll mod = 1e9+7;
ll mem(ll sum){
	if(sum == 0)return 0;
	ll &r = dp[sum];
	if(r != -1)return r;
	r = 0;
	for(ll i = 0 ; i < n ; i++){
		if(sum - a[i] >= 0 && mem(sum - a[i]) == 0){
			r = 1;
			break;
		}
	}
	return r;
}
void solve(){
	msdp(dp);
	cin >> n >> k;
	for(ll i = 0 ; i < n ; i++){
		cin >> a[i];
	}
	cout << (mem(k) ? "First" : "Second");
}
int main() {
    fast ;
	// cin >> q;
    q = 1;
    while(q--){
    	solve();
	}
}

