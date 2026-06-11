#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <numeric>
#include <queue>
#include <cmath>
#include <stack>

using namespace std;
using ll = long long;
using lli = long long int;

void ABC076D()
{
	int N;
	cin >> N;
	vector<int> ti(N);
	vector<int> Ti(N + 1);
	vector<int> vi(N+1);
	for (int i = 0; i < N; ++i)
	{
		cin >> ti[i];
		Ti[i + 1] = Ti[i] + ti[i];
	}
	for (int i = 0; i < N; ++i)
		cin >> vi[i];

	vi[N] = 0;
	for (int i = N-1; i >= 0; --i)
	{
		vi[i] = min(vi[i], vi[i + 1] + ti[i]);
	}
	for (int i = 0; i < N; ++i)
	{
		vi[i + 1] = min(vi[i + 1], vi[i] + ti[i + 1]);
	}

	int v = 0;
	double d = 0.0;
	for (int i = 0; i < N; ++i)
	{

		if (v + ti[i] < min(vi[i], vi[i + 1]))
		{
			d += v * ti[i] + 0.5 * ti[i] * ti[i];
			v += ti[i];
		}
		else
		{
			int t1 = vi[i] - v;
			int s = max(0, vi[i] - vi[i + 1]);
			int t2 = ti[i] - s;
			if (t1 <= t2)
			{
				d += v * ti[i] + 0.5 * t1 * t1 + (vi[i] - v) * (ti[i] - t1) - 0.5 * s * s;
			}
			else
			{
				double tmax = 0.5 * (ti[i] + vi[i + 1] - v);
				d += 0.5 * ((2 * v + tmax) * tmax + (vi[i + 1] + v + tmax) * (ti[i] - tmax));
			}
			v = min(vi[i], vi[i + 1]);
		}
	}
	cout << std::fixed << std::setprecision(10) << d << endl;
}

int main()
{
	ABC076D();
	return 0;
}