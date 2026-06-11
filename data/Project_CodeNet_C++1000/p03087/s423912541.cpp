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

using CC = pair<ll, ll>;

template<typename T>
constexpr T divide_floor(T a, T b)
{
	T remainder = a % b;
	return (a - remainder) / b;
}

int main()
{
	int N, Q;
	string S;
	cin >> N >> Q >> S;

	vector<int> dp(N, 0);
	char prev = S[0];
	rep_init(i, 1, N)
	{
		dp[i] = dp[i-1];
		if (prev == 'A' && S[i] == 'C')
		{
			++dp[i];
		}

		prev = S[i];
	}

	rep(i, Q)
	{
		int l, r;
		cin >> l >> r;
		--l; --r;

		cout << dp[r] - dp[l] << endl;
	}

	return 0;
}