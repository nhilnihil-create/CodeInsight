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
	int N, M;
	cin >> N >> M;

	vector<CC> P(N);

	rep(i, N)
	{
		ll A, B;
		cin >> A >> B;

		P[i] = pair<ll, ll>(A, B);
	}

	sort(P.begin(), P.end(), [](CC a, CC b) { return a.first < b.first; });

	ll ans = 0;
	rep(i, N)
	{
		if (P[i].second >= M)
		{
			ans += P[i].first * M;
			break;
		}
		else
		{
			ans += P[i].first * P[i].second;
			M -= P[i].second;
		}
	}

	cout << ans << endl;

	return 0;
}