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

int main()
{
	int N, A, B, C;
	cin >> N >> A >> B >> C;

	vector<int> l(N);
	rep(i, N)
	{
		cin >> l[i];
	}

	auto ans = numeric_limits<int>::max();
	rep(i, 1 << (N * 2))
	{
		vector<int> uA, uB, uC;
		rep(j, N)
		{
			auto k = (i >> (j * 2)) % (1 << 2);
			if (k == 0)
			{
				uA.push_back(l[j]);
			}
			else if (k == 1)
			{
				uB.push_back(l[j]);
			}
			else if (k == 2)
			{
				uC.push_back(l[j]);
			}
		}

		if (uA.empty() || uB.empty() || uC.empty())
		{
			continue;
		}

		auto sumA = accumulate(uA.begin(), uA.end(), 0);
		auto sumB = accumulate(uB.begin(), uB.end(), 0);
		auto sumC = accumulate(uC.begin(), uC.end(), 0);

		ans = min(ans, abs(sumA - A) + abs(sumB - B) + abs(sumC - C) + static_cast<int>(uA.size() + uB.size() + uC.size() - 3) * 10);
	}

	cout << ans << endl;

	return 0;
}