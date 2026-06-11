#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
#include <utility>
#include <functional>
#include <cstring>
#include <queue>
#include <stack>
#include <math.h>
#include <iterator>
#include <vector>
#include <string>
#include <set>
#include <math.h>
#include <iostream>
#include <random>
#include<map>
#include <iomanip>
#include <time.h>
#include <stdlib.h>
#include <list>
#include <typeinfo>
#include <list>
#include <set>
#include <cassert>
#include<fstream>
#include <unordered_map>
#include <cstdlib>
#include <complex>
#include <cctype>
#include <bitset>
using namespace std;
typedef string::const_iterator State;
#define Ma_PI 3.141592653589793
#define eps 1e-5
#define LONG_INF 1e18
#define GOLD 1.61803398874989484820458
#define MAX_MOD 1000000007LL
#define MOD 998244353LL
#define seg_size 262144*4
#define REP(a,b) for(long long a = 0;a < b;++a)
long long dp[5001][5001] = {};
int main() {
	long long n, aa, bb;
	cin >> n >> aa >> bb;
	REP(i, 5001) {
		REP(q, 5001) {
			dp[i][q] = LONG_INF;
		}
	}
	dp[0][0] = 0;
	REP(i, n) {
		long long a;
		cin >> a;
		for (int q = 0; q <= n; ++q) {
			if (q <= a) {
				dp[i + 1][q] = min(dp[i + 1][q], dp[i][q] + aa);
				dp[i + 1][a] = min(dp[i + 1][a], dp[i][q]);
			}
			else {
				dp[i + 1][q] = min(dp[i + 1][q], dp[i][q] + bb);
			}
		}
	}
	long long ans = LONG_INF;
	for (int i = 0; i <= n; ++i) {
		ans = min(ans, dp[n][i]);
	}
	cout << ans << endl;
	return 0;
}