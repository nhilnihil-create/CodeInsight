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
	int N, M;
	cin >> N >> M;
	vector<pair<ll, int>> bs;
	vector<pair<ll, int>> be;
	for (auto i = 0; i < M; ++i)
	{
		int a, b;
		cin >> a >> b;
		--a;
		--b;
		bs.push_back({ a, i });
		be.push_back({ b, i });
	}
	sort(bs.begin(), bs.end());
	sort(be.begin(), be.end());

	auto ans = 0;
	vector<bool> flag(M);
	auto j = 0;
	for (auto i = 0; i < M; ++i)
	{
		if (flag[be[i].second])
		{
			continue;
		}

		while (j < M && bs[j].first < be[i].first)
		{
			flag[bs[j].second] = true;
			++j;
		}
		++ans;
	}
	cout << ans << endl;

	return 0;
}