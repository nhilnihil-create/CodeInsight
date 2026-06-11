
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <cstring>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <array>
#include <cassert>
#include <bitset>
using namespace std;
using LL = long long;

string S;
int N;
int K;
int memo[345][345][345];
int dp(int i, int j, int k) {
	if (i == 0 || j == 0)return 0;
	if (memo[i][j][k] >= 0)return memo[i][j][k];
	int res = max(dp(i - 1, j, k), dp(i, j - 1, k));
	if (S[i - 1] == S[N - j])res = max(res, dp(i - 1, j - 1, k) + 1);
	if (k > 0)res = max(res, dp(i - 1, j - 1, k - 1) + 1);
	return memo[i][j][k] = res;
}

int main(void)
{
	cin >> S;
	cin >> K;
	N = S.size();
	memset(memo, 0xff, sizeof(memo));
	int ans = 0;
	for (int i = 0; i < N; ++i) {
		int can = dp(i, N - i - 1, K);
		ans = max(ans, can * 2 + 1);
	}
	for (int i = 0; i <= N; ++i) {
		int can = dp(i, N - i, K);
		ans = max(ans, can * 2);
	}
	cout << ans << endl;
	return 0;
}
