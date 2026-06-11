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
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 5e1 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	vector<int> vx, vy;
	vector<pair<int, int>> vp;
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		vx.push_back(x);
		vy.push_back(y);
		vp.emplace_back(x, y);
	}
	LL ans = 4 * INF * INF;
	sort(vx.begin(), vx.end());
	sort(vy.begin(), vy.end());
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			for (int s = 0; s < n; s++)
			{
				for (int t = s + 1; t < n; t++)
				{
					int lx = vx[i], rx = vx[j];
					int ly = vy[s], ry = vy[t];
					int sum = 0;
					for (auto &p : vp)
					{
						if (p.first >= lx && p.first <= rx && p.second >= ly && p.second <= ry) sum++;
					}
					if (sum >= k)
					{
						ans = min(ans, 1LL * (rx - lx)*(ry - ly));
					}
				}
			}
		}
	}
	cout << ans << endl;
	return 0;
}
