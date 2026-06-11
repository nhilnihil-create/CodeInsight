#include<iostream>
#include<vector>
#include<utility>
#include<map>
#include<deque>
#include<numeric>
#include<algorithm>
#include<unordered_map>
#include<cmath>
#include<string>
#include<iomanip>

using namespace std;
using ll = long long int;
constexpr int INF = 1 << 30;
constexpr ll MOD = ll(1e9 + 7);

int n;
vector<double> p;
vector<vector<double>> dp;

int main(void) {
	cin >> n;
	p = vector<double>(n + 1);
	dp = vector<vector<double>>(n + 1, vector<double>(n + 1, 0));
	for (int i = 1; i < n + 1; i++)
		cin >> p[i];
	dp[0][0] = 1;
	for (int i = 1; i < n + 1; i++) {
		for (int j = 0; j <= i; j++) {
			if (j > 0)
				dp[i][j] = dp[i - 1][j] * (1 - p[i]) + dp[i - 1][j - 1] * p[i];
			else
				dp[i][j] = dp[i - 1][j] * (1 - p[i]);
		}
	}
	double ret = 0.;
	for (int i = (n + 1) / 2; i < n + 1; i++)
		ret += dp[n][i];
	cout << fixed << setprecision(10) << ret << endl;
	return 0;
}