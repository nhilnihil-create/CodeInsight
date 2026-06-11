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
using namespace std;
#define Ma_PI 3.141592653589793
#define eps 0.00000001
#define LONG_INF 2000000000000000000
#define GOLD 1.61803398874989484820458
#define MAX_MOD 1000000007
#define REP(i,n) for(long long i = 0;i < n;++i)
#define seg_size 524288
int dp[67108864] = {};
int main() {
	for (int i = 1;i < 67108864;++i) {
		dp[i] = 300000;
	}
	string s;
	cin >> s;
	long long hashing = 0;
	int ans = 300000;
	for (int i = 0;i < s.length();++i) {
		hashing ^= (1 << (s[i] - 'a'));
		for (int q = 0;q < 27;++q) {
			long long mew = (1 << (q-1));
			if (q == 0) {
				mew = 0;
			}
			if (i == s.length() - 1) {
				ans = min(ans, dp[mew^hashing] + 1);
			}
			dp[hashing] = min(dp[(mew ^ hashing)]+1, dp[hashing]);
		}
	}
	cout << ans << endl;
	return 0;
}