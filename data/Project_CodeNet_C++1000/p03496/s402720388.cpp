#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
#include <random>
#include <cassert>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e5 + 10;
int a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	int mink = 1;
	int maxk = 1;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		if (a[i] < a[mink]) mink = i;
		if (a[i] > a[maxk]) maxk = i;
	}
	vector<pair<int, int>> ans;
	if (abs(a[maxk]) <= abs(a[mink]))
	{
		for (int i = 1; i <= n; i++)
		{
			if (i == mink) continue;
			ans.emplace_back(mink, i);
		}
		for (int i = n - 1; i >= 1; i--)
			ans.emplace_back(i + 1, i);
	}
	else
	{
		for (int i = 1; i <= n; i++)
		{
			if (i == maxk) continue;
			ans.emplace_back(maxk, i);
		}
		for (int i = 1; i < n; i++)
			ans.emplace_back(i, i + 1);
	}
	printf("%d\n", ans.size());
	for (auto& p : ans)
		printf("%d %d\n", p.first, p.second);
	return 0;
}