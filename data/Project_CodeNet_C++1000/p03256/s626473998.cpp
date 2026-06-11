#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int n,m,cnt,ch[N][2],u[N],v[N],vis[N];
vector<int> vec[N];
queue<int> q;
char s[N];
int main()
{
	scanf("%d%d",&n,&m);
	scanf("%s",s+1);
	for (int i=1;i<=m;i++)
	{
		scanf("%d%d",&u[i],&v[i]);
		ch[u[i]][s[v[i]]-'A']++;
		ch[v[i]][s[u[i]]-'A']++;
		vec[u[i]].push_back(v[i]);
		vec[v[i]].push_back(u[i]);
	} 
    for (int i=1;i<=n;i++) if (!ch[i][0]||!ch[i][1]) q.push(i),vis[i]=1;
    while (!q.empty())
    {
    	int now=q.front();q.pop();
    	for (int i=0;i<vec[now].size();i++)
    	  if (!vis[vec[now][i]])
    	    if (!--ch[vec[now][i]][s[now]-'A']) q.push(vec[now][i]),vis[vec[now][i]]=1;
	}
	for (int i=1;i<=n;i++) cnt+=(!vis[i]);
	puts(cnt?"Yes":"No");
	return 0;
}