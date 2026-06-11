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

const int N = 8e5 + 10;

LL a[N];
int h[N];
LL dp[N];
LL tree[N];

void update(int v, int l, int r, int pos, LL val) {

	if (l > pos || r < pos)
		return;

	if (l == r) {
		tree[v] = val;
		return;
	}

	int mid = (l + r) / 2;
	update(v * 2, l, mid, pos, val);
	update(v * 2 + 1, mid + 1, r, pos, val);

	tree[v] = max(tree[v * 2], tree[v * 2 + 1]);
}

LL mx(int v, int l, int r, int r1) {

	if (l > r1)return 0;

	if (r <= r1)
		return tree[v];

	int mid = (l + r) / 2;
	return max(mx(v * 2, l, mid, r1), mx(v * 2 + 1, mid + 1, r, r1));
}

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 1;i <= n;i++)
		scanf("%d", &h[i]);

	for (int i = 1;i <= n;i++)
		scanf("%lld", &a[i]);

	for (int i = 1;i <= n;i++) {
		dp[i] = mx(1, 1, n, h[i]) + a[i];
		update(1, 1, n, h[i], dp[i]);
	}

	LL ans = 0;
	for (int i = 1;i <= n;i++)
		ans = max(ans, dp[i]);

	printf("%lld\n", ans);
}