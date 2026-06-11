//apigs property
//Happiness can be found, even in the darkest of times, if one only remembers to turn on the light
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
#define C continue
#define R return
#define lx node * 2
#define rx node * 2 + 1
using namespace std;
typedef long long ll;
ll q, d, dp[100][100005], a[555555] , b[555555], k, l, m, n, o, p;
map < ll , ll > mp;
vll adj[555555];
const ll mod = 1e9+7;
ll mem(ll i , ll sum){
	if(i == n && sum == 0)R 1;
	else if(i >= n || sum < 0)R 0;
	ll &r = dp[i][sum];
	if(r != -1)R r;
	r = mem(i + 1 , sum) % mod + mem(i, sum - 1) % mod - mem(i + 1 , sum - a[i] - 1) % mod;
	r %= mod;
	if(r < 0)r += mod;
	R r;
}
void solve(){
	msdp(dp);
	cin >> n >> k;
	for(ll i = 0 ; i < n ; i++){
		cin >> a[i];
	}
	cout << mem(0 , k);
}
int main(){
    fast ;
	//cin >> q;
    q = 1;
    while(q--){
    	solve();
	}
}


