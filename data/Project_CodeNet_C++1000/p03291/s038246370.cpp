// This CODE is supported by PEPECHAN (knzk_ate)
#include <bits/stdc++.h>

using namespace std;
using ll =long long;
#define SORT(a) sort((a).begin(),(a).end())
#define rSORT(a) reverse((a).begin(),(a).end())
#define For(i, a, b)    for(int i = (a) ; i < (b) ; ++i)
#define rep(i, n)       For(i, 0, n)
#define debug(x)  cerr << #x << " = " << (x) << endl;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
void coY() {cout <<"Yes"<<endl;}
void coN(){cout <<"No"<<endl;}
const ll INF = 1LL << 60;
const int mod = 1e9+7;
//Write From this Line

ll dp[100100][4] ;
int main()
{
	string s;
	cin >> s;
	ll n = s.size() ;
	rep(i,100100){
		rep(j,4){
			dp[i][j] = 0;
		}
	}
	dp[0][0] = 1 ;
	rep(i,n){
		ll num = s[i] - 'A'+1;
		//状態numを更新する。
		rep(j,4) dp[i+1][j] = dp[i][j];

		if(s[i]=='?'){
			rep(j,4){
				dp[i+1][j] *= 3;
				dp[i+1][j] %= mod;
			}
			for(ll j = 1 ; j <= 3 ; j++){
				 dp[i+1][j] += (dp[i][j-1]);
				 dp[i+1][j] %= mod;
			}
		} else {
			dp[i+1][num] += dp[i][num-1] ;
			dp[i+1][num]%= mod;
		}
	} 
	cout << dp[n][3] << endl;
}
