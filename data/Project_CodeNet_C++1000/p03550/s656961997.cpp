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
const int N = 1e5 + 10;
int a[N];
int n;
int dp[N][2];
int dfs(int x, int o = 0)
{
	if (dp[x][o] != -1) return dp[x][o];
	int &ret = dp[x][o] = abs(a[n] - a[x - 1]);
	for (int i = x; i < n; i++)
	{
		if (o == 0)
			ret = max(ret, dfs(i + 1, o ^ 1));
		else
			ret = min(ret, dfs(i + 1, o ^ 1));
	}
	return ret;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	MEM(dp, -1);
	int x, y;
	cin >> n >> x >> y;
	for (int i = 1; i <= n; i++) cin >> a[i];
	a[0] = y;
	cout << dfs(1) << endl;
	return 0;
}
