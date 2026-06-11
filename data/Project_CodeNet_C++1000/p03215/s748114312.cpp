#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <functional>
#include <cmath>
#include <set>
#include <queue>
#include <deque>
#include <vector>
#include <climits>
#include <sstream>
#include <iomanip>
#include <map>
#include <stack>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;

int main()
{
	ll N, K;
	cin >> N >> K;
	vector<ll> a(N);
	for (auto i = 0; i < N; ++i)
	{
		cin >> a[i];
	}

	vector<ll> sum;
	sum.push_back(0);
	for (auto i = 0; i < N; ++i)
	{
		sum.push_back(a[i] + sum[i]);
	}

	vector<ll> b;
	for (auto l = 0; l < N; ++l)
	{
		for (auto r = l; r < N; ++r)
		{
			b.push_back(sum[r + 1] - sum[l]);
		}
	}
	sort(b.begin(), b.end());

	auto ans = 0ll;
	auto start = b.begin();
	for (auto i = 41; i >= 0; --i)
	{
		auto bit = 1ll << i;
		auto iter = lower_bound(start, b.end(), bit);
		auto num = (ll)(b.end() - iter);
		if (num >= K)
		{
			ans |= bit;
			start = iter;
		}
		else if (num <= 0)
		{
			continue;
		}
		
		for (auto it = iter; it != b.end(); ++it)
		{
			*it = *it & ~bit;
		}
		sort(start, b.end());
	}

	cout << ans << endl;

	return 0;
}