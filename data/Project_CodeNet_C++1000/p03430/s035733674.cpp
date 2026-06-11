#include <string>
#include <vector>
#include <map>
#include <set>
#include <deque>
#include <iostream>
#include <functional>
#include <algorithm>
#include <sstream>
#include <iterator>
#include <cmath>
#include <limits>
#include <tuple>
#include <queue>
#include <stack>

using namespace std;
typedef long long ll;

int main()
{
	string S;
	cin >> S;
	int K;
	cin >> K;
	int N = (int)S.size();
	vector<vector<vector<int>>> dp(N + 2, vector<vector<int>>(N + 2, vector<int>(K + 1)));
	for (int l = N; l > 0; l--) {
		for (int r = l; r <= N; r++) {
			for (int k = 0; k <= K; k++) {
				if (S[l - 1] == S[r - 1]) {
					dp[l][r][k] = dp[l + 1][r - 1][k] + (l == r ? 1 : 2);
				} else {
					dp[l][r][k] = max(dp[l + 1][r][k], dp[l][r - 1][k]);
					if (k > 0) 
						dp[l][r][k] = max(dp[l][r][k], dp[l + 1][r - 1][k - 1] + (l == r ? 1 : 2));
				}
			}
		}
	}
	int ans = dp[1][N][K];
	cout << ans << endl;
	return 0;
}
