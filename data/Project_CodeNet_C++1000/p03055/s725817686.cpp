#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+5;
int fir[N],snd[N],d[N];
int hed[N],to[N<<1],nxt[N<<1],cnt;
int L = 0;
inline void dfs(int x,int pre){
	d[x] = d[pre]+1;
	fir[x] = snd[x] = d[x];
	for(int i=hed[x];i;i=nxt[i]){
		int v=to[i];if(v==pre)continue;
		dfs(v,x);
		if(fir[v] >= fir[x])snd[x] = fir[x], fir[x] = fir[v];
		else if(fir[v] >= snd[x])snd[x] = fir[v];
	}
	L = max(L, fir[x]+snd[x]-2*d[x]);
}
int n;
int main()
{
	cin >> n ;
	for(int i=1;i<n;i++){
		int u,v;scanf("%d%d",&u,&v);
		++cnt;to[cnt]=v,nxt[cnt]=hed[u];hed[u]=cnt;
		++cnt;to[cnt]=u,nxt[cnt]=hed[v];hed[v]=cnt;
	}
	dfs(1,0);
	cout << (L%3==1?"Second":"First") << endl;
}