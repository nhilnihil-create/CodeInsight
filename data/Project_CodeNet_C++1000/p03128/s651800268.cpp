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
const int M = 100;
int dp[N][M];
int d[] = { 0,2,5,5,4,5,6,3,7,6 };
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	map<int, int> mc;
	int n, m;
	cin >> n >> m;
	vector<pair<int, int>> vp;
	int minv = 10;
	while (m--)
	{
		int x;
		cin >> x;
		mc[d[x]] = max(mc[d[x]], x);
		minv = min(minv, d[x]);
	}
	for (auto& p : mc)
	{
		vp.emplace_back(p.second, p.first);
	}
	sort(vp.rbegin(), vp.rend());
	dp[0][0] = 1;
	int k1 = 0, k2 = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < 100 && minv * i + j <= n; j++)
		{
			if (dp[i][j] == 0) continue;
			if (minv * i + j > n) break;
			if (minv * i + j == n) k1 = i, k2 = j;
			for (auto& p : mc)
			{
				int cost, val;
				tie(cost, val) = p;
				int o = j - minv + cost;
				if (o < 0 || o >= 100) continue;
				dp[i + 1][o] = 1;
			}
		}
	}
	while (k1)
	{
		for (auto& p : vp)
		{
			int val, cost;
			tie(val, cost) = p;
			int o = k2 + minv - cost;
			if (o < 0 || o >= 100) continue;
			if (dp[k1 - 1][o])
			{
				putchar(val + '0');
				k1--, k2 = o;
				break;
			}
		}
	}
	puts("");
	return 0;
}