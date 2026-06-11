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

ll pes(vector<ll>& v, ll b)
{
	ll sum = 0;
	rep(i, v.size())
	{
		sum += abs(v[i] - b);
	}

	return sum;
}

int main()
{
	int N;
	cin >> N;

	vector<ll> A(N);
	rep(i, N)
	{
		cin >> A[i];
		A[i] -= i + 1;
	}

	sort(A.begin(), A.end());

	int k = N / 2;
	ll ans;
	while (true)
	{
		ll p = pes(A, A[k]);

		if (k+1 < N)
		{
			if (p > pes(A, A[k+1]))
			{
				k = (N - 1 + k + 1) / 2;
				continue;
			}
		}

		if (k-1 >= 0)
		{
			if (p > pes(A, A[k-1]))
			{
				k = (k-1) / 2;
				continue;
			}
		}

		ans = p;
		break;
	}

	cout << ans << endl;
}