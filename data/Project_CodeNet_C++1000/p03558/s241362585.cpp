#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <unordered_set>
#include <cstdlib>
#include <ctime>
#include <queue>
using namespace std;

const int N = 100010;
int dp[N];
bool vis[N];

int solve(int n) {
	queue<int> q;
	memset(dp, -1, sizeof(dp));
	for (int i = 1; i < 10; i++) {
		if (dp[i % n] == -1) {
			dp[i % n] = i;
			q.push(i % n);
		    vis[i % n] = true;
		}
	}

	while (!q.empty()) {
		int u = q.front();
		q.pop();
		vis[u] = false;
		for (int i = 0; i < 10; i++) {
			int x = (10 * u + i) % n;
			if (dp[x] == -1 || dp[x] > dp[u] + i) {
				dp[x] = dp[u] + i;
				if (!vis[x]) {
					vis[x] = true;
					q.push(x);
				}
			}
		}
	}
	return dp[0];
}

int main()
{
	int n;
	scanf("%d", &n);
	
	cout << solve(n) << endl;
	return 0;
}