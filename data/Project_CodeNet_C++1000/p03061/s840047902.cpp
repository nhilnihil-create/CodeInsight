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
constexpr T gcd(T a, T b)
{
	if (a < b) swap(a, b);

	if (a % b == 0) return b;
	else return gcd(b, a % b);
}

int main()
{
	int N;
	cin >> N;

	vector<int> A(N);
	rep(i, N)
	{
		cin >> A[i];
	}

	vector<int> L(N);
	vector<int> R(N);

	L[0] = A[0];
	rep_init(i, 1, N)
	{
		L[i] = gcd(L[i-1], A[i-1]);
	}

	R[N-1] = A[N-1];
	for (int i = N-2; i >= 0; --i)
	{
		R[i] = gcd(R[i+1], A[i+1]);
	}

	int ans = 0;
	rep(i, N)
	{
		if (i == 0)
		{
			ans = max(ans, R[0]);
		}
		else if (i == N-1)
		{
			ans = max(ans, L[N-1]);
		}
		else
		{
			ans = max(ans, gcd(R[i], L[i]));
		}
	}

	cout << ans << endl;
}