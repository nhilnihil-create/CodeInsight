#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<vector>
#include<queue>
using namespace std;
char str[400005];
int a[400005],b[400005],d[400005][2];
int n,m,ans;
bool vis[400005];
vector<int>V[400005];
queue<int>Q;
int main()
{
	scanf("%d%d",&n,&m);
    scanf("%s",str+1);
    for (int i=1;i<=n;i++) a[i]=(str[i]=='A');
    for (int i=1,x,y;i<=m;i++)
    {
        scanf("%d%d",&x,&y);
        V[x].push_back(y);
        V[y].push_back(x);
        d[x][a[y]]++;
        d[y][a[x]]++;
    }
    for (int i=1;i<=n;i++)
    	if (!d[i][0] || !d[i][1]) Q.push(i);
    while (!Q.empty())
    {
        int u=Q.front();Q.pop();
        if (vis[u]) continue;
        vis[u]=true;
        ans++;
        for (int i=0;i<V[u].size();i++)
        {
            int v=V[u][i];
            d[v][a[u]]--;
            if (!d[v][a[u]]) Q.push(v);
        }
    }
    if (ans<n) printf("Yes\n"); else printf("No\n");
    return 0;
}
