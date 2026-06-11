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
    ll dp[100002];
    dp[0] = 0;
    for (ll i = 1; i <= 100001;i++){
        dp[i] = INF;
        ll power = 1;
		while(i>=power){
            chmin(dp[i], dp[i - power] + 1);
            power *= 6;
        }
        power = 1;
		while(i>=power){
            chmin(dp[i], dp[i - power] + 1);
            power *= 9;
        }
    }
    cout << dp[n] << endl;
}