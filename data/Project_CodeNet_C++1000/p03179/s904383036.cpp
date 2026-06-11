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
string s;
int dp[3030][3030];
void solve(){
	cin >> n >> s;
	auto fix = [](int &val){
		if(val >= M) val-= M;
	};
	auto sum = [](int i,int l,int r){
		if(l > r) return 0;
		return (dp[i][r] - dp[i][l-1] + M) % M;
	};
	for(int i=1;i<=n;i++){
		dp[1][i] = 1;
	}
	for(int i=2;i<=n;i++){
		for(int j=1;j<=i;j++){
			if(s[i-2] == '<'){
				dp[i][j] = sum(i-1, 1, j-1);
				/*for(int k=1;k<j;k++){
					dp[i][j] += dp[i-1][k];
					fix(dp[i][j]);
				}*/
			}
			else{
				dp[i][j] = sum(i-1, j, i);
				/*for(int k=i;k>=j;k--){
					dp[i][j] += dp[i-1][k];
					fix(dp[i][j]);
				}*/
			}
		}
		for(int j=1;j<=n;j++){
			dp[i][j] += dp[i][j-1];
			fix(dp[i][j]);
		}
	}
	/*cout << dp[2][1] << " " << dp[2][2] << endl;
	cout << dp[3][1] << " " << dp[3][3] << endl;*/
	/*int ans = 0;
	for(int i=1;i<=n;i++){
		ans += dp[n][i];
		fix(ans);
	}*/
	//cout << ans << endl;
	cout << dp[n][n] << endl;
}
int32_t main(){
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int t = 1;
  //cin >> t;
  while(t--){
    solve();
  }  
}