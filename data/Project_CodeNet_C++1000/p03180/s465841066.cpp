#include <bits/stdc++.h>
#define ll long long
//#define endl "\n"
#define pb push_back
#define ms(v,x) memset(v,x,sizeof(v))
#define ff first
#define ss second
#define td(v) v.begin(),v.end()
#define rep(i,a,n) for (int i=(a);i<(n);i++)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define re(v) {for(auto &_re : v) cin >> _re;}
#define rre(v){for(auto &_re : v) for(auto &_rre : _re) cin >> _rre;}
#define pr(v) {for(auto _pr : v) cout << _pr << " "; cout << endl;}
#define prr(v) {for(auto _prr : v) cout << _prr.ff << " " << _prr.ss << endl;}
#define eb emplace_back
using namespace std;
const int M = 1e9 + 7;
const ll mod = 998244353;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
//#define int long long
int n;
ll a[16][16];
ll subset[1<<16];
ll dp[1<<16];
ll f(int b){ // O(3^n);
	ll &x = dp[b];
	if(x!=-1) return x;
	// iterate over all subsets of mask
	int mask = b ^ ((1<<n) - 1);
	x = -1e18;
	for(int i = mask; i > 0; i = (i-1) & mask){
  	x = max(x, subset[i] + f(b | i));
  }
  return x;
}
void solve(){
	cin >> n;
	rep(i,0,n) rep(j,0,n) cin >> a[i][j];
	for(int i=0;i<1<<n;i++){
		for(int j=0;j<n;j++){
			if(!(i>>j&1)) continue;
			for(int k=j+1;k<n;k++){
				if(!(i>>k&1)) continue;
				subset[i] += a[j][k];
			}
		}
	}
	ms(dp, -1);
	dp[(1<<n) - 1] = 0;
	cout << f(0) << endl;
}
int32_t main(){
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int t = 1;
  //cin >> t;
  while(t--){
    solve();
  }  
}