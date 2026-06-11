#include<bits/stdc++.h>
#define gc getchar()
#define ll long long
#define pb push_back
#define mk make_pair
#define rint register int
using namespace std;
inline int read(){char ch=gc;int w=1,s=0;while(!isdigit(ch)){if(ch=='-') w=-1;ch=gc;};while(isdigit(ch)){s=s*10+ch-'0';ch=gc;} return w*s;}
struct node{
	int to,next;
}e[1000010];
int du[1000100][2],h[1000010],tot,x[1000010],y[1000010];
int n,m,vis[1000010];
queue<int> q;
inline void add(int from,int to){e[++tot].next=h[from];h[from]=tot;e[tot].to=to;}
char s[1000010];
int main()
{
	n=read();m=read();
	scanf("%s",s+1);int len=strlen(s+1);for(rint i=1,u,v;i<=m;++i) u=read(),v=read(),add(u,v),add(v,u),x[i]=u,y[i]=v;
	for(rint i=1;i<=m;++i) du[x[i]][s[y[i]]-'A']++,du[y[i]][s[x[i]]-'A']++;
	for(rint i=1;i<=n;++i) if(!du[i][0]||!du[i][1]) vis[i]=1,q.push(i);
	while(!q.empty())
	{
		int u=q.front();q.pop();
		for(rint i=h[u];i;i=e[i].next)
		{
			int to=e[i].to;if(vis[to]) continue;
			du[to][s[u]-'A']--;
			if(!du[to][1]||!du[to][0])
			{
				q.push(to);
				vis[to]=1;
			}
		}
	}int ans=0;
	for(rint i=1;i<=n;++i) ans+=vis[i];
	if(ans==n)
	{
		cout<<"No\n";
	}
	else{
		cout<<"Yes\n";
	}
	return 0;
}

