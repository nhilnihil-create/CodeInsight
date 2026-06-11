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
	map<int, int> D;
	for (auto i = 0; i < N; ++i)
	{
		int d;
		cin >> d;
		++D[d];
	}

	vector<int> list;
	list.push_back(0);
	bool flag = true;
	for (auto d : D)
	{
		for (auto i = 0; i < d.second; ++i)
		{
			if (flag)
			{
				list.push_back(d.first);
			}
			else
			{
				list.push_back(24 - d.first);
			}
			flag = !flag;
		}
	}

	sort(list.begin(), list.end());
	auto result = 24;
	for (auto i = 0; i < list.size() - 1; ++i)
	{
		result = min(result, list[i + 1] - list[i]);
	}

	cout << result << endl;

	return 0;
}