#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
vector<int> adj[maxn];
int dis[maxn];

int dfs(int cur)
{
	if(dis[cur] != 1) return dis[cur];
	else{

		int temp = 0;
		for(auto i : adj[cur]){
			temp = max(temp, dfs(i));
		}
		dis[cur] += temp;
	}
	return dis[cur];
}
int main(int argc, char const *argv[])
{
	int n, m; scanf("%d %d", &n, &m);
	int x, y;
	fill(dis, dis + n + 1, 1);
	for(int i = 0; i < m; i++){
		scanf("%d %d", &x, &y);
		adj[x].push_back(y);
	}
	int ans = 1;
	for(int i = 1; i <= n; i++) ans = max(ans, dfs(i));
	/*	
	for(int i = 1; i <= n; i++){
		printf("%d ", dis[i]);
	}
	*/
	printf("%d\n", ans-1);

	return 0;
}