#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>

#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
//#include <tchar.h>
//#include <intrin.h>

#define F first
#define S second
#define LL long long
#define MOD 1000000007
#define INF 2000000000
#define LINF 1000000000000000000

using namespace std;

const int N = 2e5 + 10;

LL dp[110][N];
LL a[N], pr[N];
int n, k;


int main()
{
	
	scanf("%d%d", &n, &k);

	for (int i = 1;i <= n;i++)
		cin >> a[i];

	for (int i = 1;i <= n;i++)
		pr[i] = pr[i - 1] + a[i];
	
	for (int i = 0;i <= k;i++)
		dp[0][i] = 1;

	for (int i = 1;i <= n;i++) {
		for (int j = 0;j <= k;j++)
			dp[i][j] = (dp[i - 1][j] - (a[i] >= j ? 0 : dp[i - 1][j - a[i] - 1]) + MOD) % MOD;

		for (int j = 1;j <= k;j++)
			dp[i][j] = (dp[i][j - 1] + dp[i][j]) % MOD;
	}

	printf("%lld\n", (dp[n][k] - dp[n][k - 1] % MOD + MOD) % MOD);
	cin >> n;
}