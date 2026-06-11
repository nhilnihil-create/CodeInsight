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

void getDivisor(ll n, vector<ll>& result)
{
	for (auto i = 1ll; i * i <= n; ++i)
	{
		if (n % i == 0)
		{
			result.push_back(i);
			if (i != n / i)
			{
				result.push_back(n / i);
			}
		}
	}
}

int main()
{
	ll N, M;
	cin >> N >> M;
	vector<ll> div;
	getDivisor(M, div);
	auto ans = 1ll;
	for (auto i = 0; i < (int)div.size(); ++i)
	{
		if (M / div[i] >= N)
		{
			ans = max(ans, div[i]);
		}
	}

	cout << ans << endl;

	return 0;
}