#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr long long MOD = 1000000007;
constexpr long long INF = 1LL << 60;
const long double PI = acosl(-1.0);
constexpr long double EPS = 1e-11;
template<class T> inline bool chmin(T& a, T b) {
	if (a > b) {
		a = b;
		return true;
	}
	return false;
}
template<class T> inline bool chmax(T& a, T b) {
	if (a < b) {
		a = b;
		return true;
	}
	return false;
}
int main(){
ll n;
cin >> n;
vector<double> p(n);
for (ll i = 0; i < n; i++) cin >> p[i];
double dp[n + 2][n + 2];//dp[i][j]:=i枚目まで見て、j枚表の確率
for (ll i = 0; i < n + 2;i++){
    for (ll j = 0; j < n + 2;j++){
        dp[i][j] = 0.0;
    }
}
dp[0][0] = 1;
for (ll i = 1; i < n+1;i++){
    for (ll j = 0; j < n + 1;j++){
        if (j > 0) dp[i][j] = dp[i - 1][j - 1] * p[i-1] + dp[i - 1][j] * (1.0 - p[i-1]);
		else
            dp[i][j] = dp[i - 1][j] * (1.0 - p[i-1]);
    }
}
double ans = 0;
for (ll i = (n+1)/2; i < n+1; i++) ans += dp[n][i];
cout << fixed << setprecision(10) << ans << endl;
}