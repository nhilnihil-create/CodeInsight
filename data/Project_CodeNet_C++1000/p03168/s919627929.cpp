#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int mxn = 3001;
const int M = 1e9 + 7;

int n;
double ans;

int main() {
	ans = 0.0;
	cin >> n;
	vector<double> p(n);
	
	for(int i = 0; i < n; i++) {
		cin >> p[i];
	}
	vector<double> dp(n+1);
	dp[0] = 1.0;
	
	for(int i = 1; i <= n; i++) {
		vector<double> new_dp(n+1);
		for(int heads = 0; heads <= i; heads++) {
			if(heads == 0) {
				new_dp[heads] = dp[heads] * (1 - p[i-1]);
			}
			else new_dp[heads] = dp[heads] * (1 - p[i-1]) + dp[heads-1] * p[i-1];
		}
		dp = new_dp;
	}
	
	for(int i = 1; i <= n; i++) {
		if( i > (n-i)) {
			ans += dp[i];
		}
	}
	cout << setprecision(10);
	cout << ans << "\n";
}
