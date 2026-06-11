/*DavitMarg*/
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#include <map>
#include <unordered_map>
#include <bitset>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <iterator>
#include <ctype.h>
#include <stdlib.h>  
#include <cassert>
#include <fstream>
#define mod 1000000007ll
#define LL long long
#define LD long double
#define MP make_pair
#define PB push_back
#define all(v) v.begin(),v.end()
using namespace std;

int n,used[200005],dp[200005],mx;
vector<int> g[200005];

void dfs(int v,int d)
{
	used[v] = 1;
	for (int i = 0; i < g[v].size(); i++)
	{
		int to = g[v][i];
		if (used[to])
			continue;
		dfs(to,d+1);
		mx = max(mx, dp[v] + 1 + dp[to]);
		dp[v] = max(dp[v], dp[to] + 1);
	}
	mx = max(mx, dp[v] + d);
}

int main()
{
	cin >> n;
	for (int i = 1; i <= n - 1; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		g[a].PB(b);
		g[b].PB(a);
	}
	for (int i = 1; i <= n; i++)
		if (g[i].size() == 1)
		{
			dfs(i,0);
			break;
		}
	mx %= 3;
	if (mx == 1)
		cout << "Second" << endl;
	else
		cout << "First" << endl;
	return 0;
}

/*

*/