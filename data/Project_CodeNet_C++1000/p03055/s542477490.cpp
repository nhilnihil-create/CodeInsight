#include <bits/stdc++.h>

#define PI 3.14159265358979323846264338327950288419

using namespace std;

int n;
vector<int> e[200005];

int dp[200005], dep[200005];

void dfs(int id, int pv){
	int fm = 0, sm = 0;
	for(auto nx: e[id]){
		if(nx != pv){
			dfs(nx, id);
			dp[id] = max(dp[id], dp[nx]);
			if(dep[nx] + 1 > fm){
				sm = fm;
				fm = dep[nx] + 1;
			}else if(dep[nx] + 1 > sm){
				sm = dep[nx] + 1;
			}
		}
	}
	dep[id] = fm;
	dp[id] = max(dp[id], fm + sm);
}

int main(){
	scanf("%d", &n);
	for(int i = 1; i < n; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		e[a].push_back(b);
		e[b].push_back(a);
	}
	dfs(1, 0);
	int diam = dp[1] + 1; // #nodes on diam = length + 1
	if(diam % 3 == 2){
		printf("Second\n");
	}else{
		printf("First\n");
	}
	return 0;
}