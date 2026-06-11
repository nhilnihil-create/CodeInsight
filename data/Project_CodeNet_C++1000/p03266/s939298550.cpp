#include <iostream>
#include <iomanip>
#include <cassert>

#include <cstring>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <limits>
#include <queue>
#include <unordered_map>
#include <list>
#include <set>
#include <numeric>
using namespace std;

using ll = long long;

#define rep_init(i, init, n) for(int i = (init); i < (n); ++i)
#define rep(i, n) rep_init(i, 0, n)

template<typename T>
constexpr T int_pow(T b, uint64_t e)
{
	if (e == 0) return 1;
	if ((e & 0x1) == 0) return int_pow(b * b, e >> 1);
	else return b * int_pow(b * b, e >> 1);
}

int main()
{
	ll N, K;
	cin >> N >> K;

	ll ans = 0;
	if (K % 2 == 0)
	{
		ll K_num = N / K;
		ll Kper2_num = (N + K / 2) / K;

		ans = int_pow(K_num, 3) + int_pow(Kper2_num, 3);
	}
	else
	{
		ll K_num = N / K;

		ans = int_pow(K_num, 3);
	}

	cout << ans << endl;
}