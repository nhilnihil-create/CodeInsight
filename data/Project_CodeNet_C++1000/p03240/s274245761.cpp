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
using namespace std;

using ll = long long;

#define rep_init(i, init, n) for(int i = (init); i < (n); ++i)
#define rep(i, n) rep_init(i, 0, n)

int main()
{
	int N;
	cin >> N;
	vector<int> x(N), y(N), h(N);

	int index_HNotZ;
	rep(i, N)
	{
		cin >> x[i] >> y[i] >> h[i];
		if (h[i] != 0)
		{
			index_HNotZ = i;
		}
	}

	ll ansX, ansY, ansH;
	bool isAns = false;
	rep(i, 101)
	{
		rep(j, 101)
		{
			isAns = true;
			ll cand_h = h[index_HNotZ] + abs(x[index_HNotZ] - i) + abs(y[index_HNotZ] - j);
			rep(k, N)
			{
				auto a = abs(x[k] - i) + abs(y[k] - j);
				if (cand_h != h[k] + abs(x[k] - i) + abs(y[k] - j))
				{
					if (h[k] != 0 || cand_h > abs(x[k] - i) + abs(y[k] - j))
					{
						isAns = false;
						break;
					}
				}
			}

			if (isAns)
			{
				ansX = i;
				ansY = j;
				ansH = cand_h;

				break;
			}
		}

		if (isAns) break;
	}

	cout << ansX << " " << ansY << " " << ansH << endl;
	
	return 0;
}