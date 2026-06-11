#include <stdio.h>
#include <math.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h>
#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
#include <string>
#include <unordered_map>
#include <map>
#include <queue>
#include <set>
#include <stack>

using namespace std;

#define long long long
#define fi first
#define se second
typedef pair<int,int> ii;

int n;
int jar[200003];
vector<int> vec[200003];

void dfs(int u)
{
	for(auto v : vec[u])
	{
		if(jar[v] == -1)
		{
			jar[v] = jar[u]+1;
			dfs(v);
		}
	}
}

int main()
{
	// ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen("input.in", "r", stdin);

	int n; scanf("%d", &n);
	for(int i = 1; i < n; i++)
	{
		int u, v;
		scanf("%d %d", &u, &v);
		vec[u].push_back(v);
		vec[v].push_back(u);
	}
	memset(jar, -1, sizeof jar);
	jar[1] = 0;
	dfs(1);

	int mx = -1, u;
	for(int i = 1; i <= n; i++)
	{
		if(jar[i] > mx)
		{
			mx = jar[i];
			u = i;
		}
	}

	memset(jar, -1, sizeof jar);
	jar[u] = 0;
	dfs(u);

	mx = -1;
	for(int i = 1; i <= n; i++)
		mx = max(mx, jar[i]);

	printf("%s", (mx%3 == 1)? "Second\n" : "First\n");
}








