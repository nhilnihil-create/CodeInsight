# include <iostream>
# include <algorithm>
# include <vector>
# include <string>
# include <set>
# include <map>
# include <cmath>
# include <iomanip>
# include <functional>
# include <utility>
# include <stack>
# include <queue>
# include <list>
# include <bitset>
# include <complex>
#include<limits.h>
#include<unordered_map>
#include<unordered_set>
#include<deque>
#include<cstdio>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
constexpr long long MOD = 1000000000 + 7;
constexpr long long INF = 1000000000;
const double PI = acos(-1);

string S;
bitset<26> B[1000000] = {};
int dp[1<<26];
int main() {
	cin >>S;
	for (LL i = 0; i < S.size(); i++) {
		if (i > 0)
			B[i] = B[i - 1];
		B[i][S[i] - 'a'].flip();
	}
	for (LL i = 0; i <(1<<26); i++)
		dp[i] = INF;
	dp[0] = 0;
	for (LL i = 0; i < S.size(); i++) {
		LL BB = B[i].to_ullong();
		if (B[i].count() < 2) {
			dp[BB] = 1;
			continue;
		}
		for (int j = 0; j < 26; j++) {
			dp[BB] = min(dp[BB^(1 << j)]+1,dp[BB]);
		}
	}
	LL Bi = B[S.size()-1].to_ullong();
	cout << dp[Bi] << endl;
	return 0;
}
