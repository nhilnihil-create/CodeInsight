#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const double pi=3.141592653589793;
typedef unsigned long long ull;
typedef long double ldouble;
const ll INF=1e18;
#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main(){
	// 小数点以下第15桁まで表示させる
    cout.precision(15);
    cout << fixed;
	int n;
	cin >> n;
	vector<double> p(n);
	rep(i, n) cin >> p[i];
	// i番目までコインを投げたときにj回表が出る確率
	vector<vector<double> > dp(n+1, vector<double> (n+1));
	dp[0][0] = 1;
	rep2(i, 1, n+1) {
		rep(j, n + 1) {
			if(j == 0) dp[j][i] = dp[j][i-1] * (1 - p[i-1]);
			else dp[j][i] = dp[j][i-1] * (1-p[i-1]) + dp[j-1][i-1] * p[i-1];
		}
	}
	double ans = 0;
	rep2(i, (n+1)/2, n+1) {
		ans += dp[i][n];
	}
	cout << ans << endl;
}