#include <algorithm>
#include <climits>
#include <functional>
#include <iterator>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

#ifdef _MSC_VER
using ll = __int64;
using ull = unsigned __int64;
#else
using ll = long long int;
using ull = unsigned long long int;
#endif

// 二乗を計算する。
ll sq(ll x) { return x * x; }

// 領域内にいるか。
bool within(ll x, ll min, ll max) {
	return min <= x && x <= max;
}

// container の中から key より小さい値を見つける。
// 見つからない場合は container.end() を返す。
template<typename T>
typename T::iterator less_than(T& container, typename T::key_type& key) {
	typename T::iterator prev = container.lower_bound(key);
	if (prev == container.begin()) prev = container.end();
	else prev--;
	return prev;
}

// container の中から key より大きい値を見つける。
// 見つからない場合は container.end() を返す。
template<typename T>
typename T::iterator greater_than(T& container, typename T::key_type& key) {
	return container.upper_bound(key);
}

// b^e (mod m) を求める
ll modpow(ll b, ll e, ll m) {
	ll result = 1;
	while (e > 0) {
		if ((e & 1) == 1) result = (result * b) % m;
		e >>= 1;
		b = (b * b) % m;
	}
	return result;
}


// ここから解法


int main(void) {
	std::ios_base::sync_with_stdio(false);

	int N;
	cin >> N;
	cout << ((N - 2) * 180) << endl;

	return 0;
}

