#include<bits/stdc++.h>
//#define int long long
using namespace std;
const int N=1e5+10;
int n,m,col[N],cnt[2],tot,flag; long long res;
vector<int> g[N];
inline void add(int a,int b){g[a].push_back(b),g[b].push_back(a);}
void dfs(int x,int co){
	col[x]=co; cnt[co]++;
	for(int to:g[x]){
		tot++;
		if(col[to]==-1)	dfs(to,co^1);
		else if(col[to]==co)	flag=1;
	}
}
signed main(){
	cin>>n>>m; memset(col,-1,sizeof col);
	for(int i=1,a,b;i<=m;i++)	scanf("%d %d",&a,&b),add(a,b);
	for(int i=1;i<=n;i++)	if(col[i]==-1){
		tot=cnt[0]=cnt[1]=flag=0; dfs(i,1); tot/=2;
		if(flag)	res+=1LL*(cnt[0]+cnt[1])*(cnt[0]+cnt[1]-1)/2-tot;
		else	res+=1LL*cnt[0]*cnt[1]-tot;
	}
	cout<<res;
	return 0;
}