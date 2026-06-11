// by Balloons
#include <cstdio>
#include <cstring>
#include <vector>
#include <iostream>
#include <algorithm>
#define mpr make_pair
#define debug() puts("okkkkkkkk")
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)

using namespace std;

typedef long long LL;

const int inf = 1 << 30;

const int maxn=2e5+5;
char s[maxn];
int n,m;
vector<int>g[maxn]; 
int vis[maxn];
int cnt[maxn][3];

void dfs(int x){
	vis[x]=1;
	for(int i=0;i<g[x].size();i++){
		int u=g[x][i];
		if(vis[u])continue;
//		printf("%d %d %d\n",u,s[x]-'A',cnt[u][s[x]-'A']);
		--cnt[u][s[x]-'A'];
		if(cnt[u][0]==0||cnt[u][1]==0)dfs(u);
	}
}

int main(){
	scanf("%d%d",&n,&m);
	scanf("%s",s+1);
	for(int i=1;i<=m;i++){
		int x,y;scanf("%d%d",&x,&y);
		g[x].push_back(y);g[y].push_back(x);
		cnt[x][s[y]-'A']++;cnt[y][s[x]-'A']++;
	}
	for(int i=1;i<=n;i++){
//		printf("i=%d,cnt[][]=%d %d\n",i,cnt[i][0],cnt[i][1]);
		if(!vis[i]&&(cnt[i][0]==0||cnt[i][1]==0))dfs(i);
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
//			printf("i=%d\n",i);
			return puts("Yes"),0;
		}
	}
	puts("No");

	return 0;
}
