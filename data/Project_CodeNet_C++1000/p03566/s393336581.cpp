#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <functional>
#include <cmath>
#include <set>
#include <queue>
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
	vector<int> t(N);
	vector<int> v(N);
	vector<int> maxV;
	for (auto i = 0; i < N; ++i)
	{
		cin >> t[i];
	}
	for (auto i = 0; i < N; ++i)
	{
		cin >> v[i];
	}

	t.push_back(0);
	v.push_back(0);
	maxV.push_back(0);
	for (auto i = 0; i <= N; ++i)
	{
		if (maxV[i] > v[i])
		{
			maxV[i] = v[i];
			for (auto j = i - 1; j >= 0; --j)
			{
				if (maxV[j] <= maxV[j + 1])
				{
					break;
				}
				auto diff = maxV[j] - maxV[j + 1];
				maxV[j] -= max(0, diff - t[j]);
			}
		}
		maxV.push_back(min(maxV[i] + t[i], v[i]));
	}

	auto result = 0.0;
	for (auto i = 0; i < N + 1; ++i)
	{
		auto v0 = maxV[i];
		auto v1 = maxV[i + 1];
		if (v0 > v1)
		{
			auto temp = v0;
			v0 = v1;
			v1 = temp;
		}

		if (v1 >= v0 + t[i])
		{
			result += v0 * t[i];
			result += (v1 - v0) * t[i] / 2.0;
		}
		else if (v1 >= v[i])
		{
			auto temp = v1 - v0;
			result += temp * temp / 2.0;
			result += temp * v0;
			result += (t[i] - temp) * v1;
		}
		else if (v[i] - v0 + v[i] - v1 <= t[i])
		{
			auto temp = v[i] - v0;
			result += temp * temp / 2.0;
			result += v0 * temp;
			auto temp2 = v[i] - v1;
			result += temp2 * temp2 / 2.0;
			result += v1 * temp2;
			result += v[i] * (t[i] - temp - temp2);
		}
		else
		{
			auto t1 = (v1 - v0 + t[i]) / 2.0;
			auto t2 = t[i] - t1;
			result += t1 * t1 / 2.0;
			result += v0 * t1;
			result += t2 * t2 / 2.0;
			result += v1 * t2;
		}
	}

	cout << fixed << setprecision(10) << result << endl;

	return 0;
}