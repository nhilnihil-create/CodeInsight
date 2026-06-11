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
#include <cassert>
//#include <tchar.h>
//#include <intrin.h>

#define F first
#define S second
#define LL long long
#define MOD 1000000007
#define INF 1000000000
#define LINF 1000000000000000000

using namespace std;

const int N = 2e5 + 10;

int dp[N][2];
vector<int>adj[N];

LL add(LL a, LL b) {
	
	return (a + b) % MOD;
}

LL mult(LL a, LL b) {

	return (a*b) % MOD;
}

void dfs(int i, int pr) {

	dp[i][0] = dp[i][1] = 1;

	for (auto x : adj[i])
		if (x == pr)continue;
		else {
			dfs(x, i);
			dp[i][0] = mult(dp[i][0], add(dp[x][0], dp[x][1]));
			dp[i][1] = mult(dp[i][1], dp[x][0]);
		}
		return;
}

int main() {
		
	int n;
	scanf("%d", &n);

	for (int i = 0;i < n - 1;i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	dfs(1, 1);
	printf("%lld\n", add(dp[1][0], dp[1][1]));
	cin >> n;
}