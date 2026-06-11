#include <iostream>
#include <iomanip>
#include <algorithm>
#include <utility>
#include <cmath>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <deque>
#include <utility>
#include <cctype>

using namespace std;

using ll = long long;
using P = pair<double, double>;

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define mkp(a, b) make_pair(a, b)




int main() {
	int n;
	cin >> n;

	vector<int> ps(n + 1,0);

	for(int i = 2; i <= n; i++) {
		int cur = i;
		for(int j = 2; j * j <= n; j++) {
			while(cur % j == 0) {
				ps[j]++;
				cur /= j;
			}
		}
		if (cur > 1) {
			ps[cur] ++;
		}
	}

	int dp[n + 1][2][3];
	
	dp[1][0][0] = 1;
	dp[1][1][0] = 0;
	dp[1][0][1] = 0;
	dp[1][1][1] = 0;
	dp[1][0][2] = 0;
	dp[1][1][2] = 0;

	for (int i = 2; i <= n; i++) {
		for(int j = 0; j < 3; j++) {
			dp[i][0][j] = dp[i - 1][0][j]; 
			dp[i][1][j] = dp[i - 1][1][j];

		}
		if (ps[i] >= 3 - 1) {
			dp[i][1][0] += dp[i - 1][0][0];
			dp[i][1][1] += dp[i - 1][0][1];
			dp[i][1][2] += dp[i - 1][0][2];
		}

		if (ps[i] >= 5 - 1) {
			dp[i][0][1] += dp[i - 1][0][0];
			dp[i][1][1] += dp[i - 1][1][0];
			dp[i][0][2] += dp[i - 1][0][1];
			dp[i][1][2] += dp[i - 1][1][1];
		}
		if (ps[i] >= 15 - 1) {
			dp[i][1][1] += dp[i - 1][0][0];
			dp[i][1][2] += dp[i - 1][0][1];
		}
		if (ps[i] >= 25 - 1) {
			dp[i][0][2] += dp[i - 1][0][0];
			dp[i][1][2] += dp[i - 1][1][0];
		}
		if (ps[i] >= 75 - 1) {
			dp[i][1][2] += dp[i - 1][0][0];
		}
	}



	cout << dp[n][1][2] << endl;




	return 0;
}
