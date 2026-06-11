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
#define INF 200000000
#define LINF 1000000000000000000

using namespace std;

const int N = 4e2 + 10;

LL a[N];
LL pr[N];
LL dp[N][N];

int main()
{
	int n;
	scanf("%d", &n);

	for (int i = 1;i <= n;i++)
		scanf("%lld", &a[i]), pr[i] = pr[i - 1] + a[i];
	
	for (int L = n;L >= 1;L--)
		for (int R = L;R <= n;R++) 
			if (R != L) {
				LL mn = LINF;
				for (int i = R - 1;i >= L;i--)
					mn = min(mn, dp[L][i] + dp[i + 1][R]);
				dp[L][R] = mn + pr[R] - pr[L - 1];
			}

	printf("%lld\n", dp[1][n]);
}