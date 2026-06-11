#include <iostream>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <stack>
#include <cstring>
#include <istream>
#include<cmath>
#include<map>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<cstring>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 5;
int k;
int vis[60][maxn];
int dfs(int x, int y) {
	if (x < 0) return 0;
	if (x == 0 && y == 0)return 1;
	if (vis[x][y]) return 0;
	vis[x][y] = 1;
	for (int s = 0; s < 10; s++)
		if (dfs(x - s, (y * 10 + s) % k))return 1;
	return 0;
}
int main()
{
	while (~scanf("%d", &k)) {
		int m = 0;
		int n = k;
		while (n) {
			for (int i = 0; i < n; i++)
				m += n % 10;
			n /= 10;
		}
		memset(vis, 0, sizeof(vis));
		int ans = m;
		for (int j = 1; j < m; j++) {
			if (dfs(j, 0)) {
				ans = j;
				break;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
