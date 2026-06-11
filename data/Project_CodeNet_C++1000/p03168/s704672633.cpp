#include<bits/stdc++.h>
using namespace std;
#define fastio std::ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define fileIO freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout)
#define int long long int
#define F first
#define S second
#define pb push_back
#define M 1000000007
#define inf 1e18
#define endl "\n"
#define jam(x) cout<<"Case #"<<x<<": "
#define N 100005
#define float double
#define opFloating(x) cout<<fixed<<setprecision(10)<<x

void display2D( vector<vector<float> > &v ) {
	int n = v.size();
	int m = v[0].size();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << v[i][j] << " ";
		}
		cout << endl;
	}
}

std::vector<float> ph;
float ans;
int need;
// float sol(int cur, int n , int h, float temp) {
// 	if (cur == n and h >= need) {
// 		return temp;
// 	}
// 	else if (cur == n) return 0.0;

// 	float ans = 0.0;
// 	temp = temp * ph[cur];
// 	ans += sol( cur + 1, n , h + 1, temp);
// 	//temp = temp / ph[cur];
// 	temp = temp * (1 - ph[cur]);
// 	ans += sol( cur + 1, n , h, temp);

// 	return ans;
// }



int32_t main() {
	fastio;
#ifndef ONLINE_JUDGE
	fileIO;
#endif
	ans = 0;
	int n;
	cin >> n;
	need = (n / 2) + 1;
	ph.resize(n + 1);
	for (int i = 1; i <= n; ++i) {
		cin >> ph[i];
	}
	//if (n == 1) {cout << ph[1]; return 0;}
	vector< vector<float> > dp(n + 1, vector<float>(n + 1, 0.0));
	dp[0][0] = 1;
	for (int i = 1; i <= n; i++) {
		dp[i][0] = dp[i - 1][0] * (1 - ph[i]);
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			dp[i][j] = dp[i - 1][j] * (1 - ph[i]) + dp[i - 1][j - 1] * ph[i];
		}
	}

	float ans = 0;
	for (int i = need; i <= n; i++) {
		ans += dp[n][i];
	}
	//display2D(dp);
	opFloating(ans);
}