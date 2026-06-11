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
	int N;
	cin >> N;
	vector<int> t(N + 2);
	vector<int> v(N + 2);
	for (auto i = 0; i < N; ++i)
	{
		cin >> t[i + 1];
	}
	for (auto i = 0; i < N; ++i)
	{
		cin >> v[i + 1];
	}

	vector<int> sum(N + 3);
	for (auto i = 0; i < N + 2; ++i)
	{
		sum[i + 1] += sum[i] + t[i];
	}

	auto ans = 0.0;
	vector<double> minV;
	for (auto ct = 0.0; ct <= sum[N + 2]; ct += 0.5)
	{
		double temp = INT_MAX;
		for (auto i = 0; i < N + 2; ++i)
		{
			auto vel = 0.0;
			if (ct < sum[i])
			{
				vel = v[i] + sum[i] - ct;
			}
			else if (ct > sum[i + 1])
			{
				vel = v[i] + ct - sum[i + 1];
			}
			else
			{
				vel = v[i];
			}
			temp = min(temp, vel);
		}
		minV.push_back(temp);
	}
	for (auto i = 0; i < (int)minV.size() - 1; ++i)
	{
		ans += (minV[i] + minV[i + 1]) / 4;
	}
	cout << fixed << setprecision(7) << ans << endl;

	return 0;
}