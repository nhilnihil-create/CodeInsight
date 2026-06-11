#include<bits/stdc++.h>
#define ll long long
#define dbg1(x) cerr<<#x<<"="<<(x)<<" "
#define dbg2(x) cerr<<#x<<"="<<(x)<<"\n"
#define dbg3(x) cerr<<#x<<"\n"
using namespace std;
#define reg register
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
	return x*f;
}
const int MN=2005,inf=1e9+5;
int N,K,Q;
int id[MN],a[MN];
bool cmp(int x,int y){return a[x]<a[y];}
int bel[MN],len[MN],cnt,bl;bool in[MN];
int solve(int pos)
{
	memset(in,0,sizeof in);
	cnt=bl=0;reg int i,j,k;
	for(i=1;i<=N;++i)
	{
		for(;i<=N&&a[i]<a[pos];++i);
		for(j=i;j<=N&&a[j]>=a[pos];++j);--j;
		for(len[++bl]=j-i+1,k=i;k<=j;++k)
			bel[k]=bl,in[k]=true;
		i=j;
	}
	for(i=1;i<=N;++i)if(in[id[i]]&&len[bel[id[i]]]>=K)
	{
		--len[bel[id[i]]];
		if(++cnt==Q)return a[id[i]]-a[pos];
	}
	return inf;
}


int main()
{
	N=read();K=read();Q=read();
	reg int i;
	for(i=1;i<=N;++i)a[id[i]=i]=read();
	sort(id+1,id+N+1,cmp);
	int ans=inf;
	for(i=1;i<=N;++i) ans=min(ans,solve(i));
	return 0*printf("%d\n",ans);
}