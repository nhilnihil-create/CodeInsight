#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int mxn = 3001;
const int M = 1e9 + 7;

int n;
double ans;

//void rec(vector<double> p, int i, int heads, double prob) {
	//cerr << i << " " << heads << " " << " " << prob << "\n";
	//if(i >= n) {
		//if(heads > (n - heads)) {
			//ans += prob;
		//}
		//return;
	//}

	//rec(p, i+1, heads + 1, prob * p[i]);
	//rec(p, i+1, heads, prob * (1 - p[i]));
//}

int main() {
	ans = 0.0;
	cin >> n;
	vector<double> p(n);
	
	for(int i = 0; i < n; i++) {
		cin >> p[i];
	}
	vector<vector<double>> dp(n+1, vector<double> (n+1));
	dp[0][0] = 1.0;
	
	for(int i = 1; i <= n; i++) {
		for(int heads = 0; heads <= i; heads++) {
			if(heads == 0) {
				dp[i][heads] = dp[i-1][heads] * (1 - p[i-1]);
			}
			else dp[i][heads] = dp[i-1][heads] * (1 - p[i-1]) + dp[i-1][heads-1] * p[i-1];
		}
	}
	
	for(int i = 1; i <= n; i++) {
		if( i > (n-i)) {
			ans += dp[n][i];
		}
	}
	cout << setprecision(10);
	cout << ans << "\n";
}
