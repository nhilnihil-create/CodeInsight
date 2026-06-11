/*8.20*/
#include<bits/stdc++.h>
#define ll long long
#define dbg1(x) cerr<<#x<<"="<<(x)<<" "
#define dbg2(x) cerr<<#x<<"="<<(x)<<"\n"
#define dbg3(x) cerr<<#x<<"\n"
using namespace std;
#define reg register
#define P pair<int,int>
#define mp make_pair
#define fi first
#define se second
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
	return x*f;
}
const int MN=262200;
int N,S,ans;
P a[MN];
P Merge(P a,P b){if(a.fi<b.fi)swap(a,b);return mp(a.fi,max(a.se,b.fi));}
int main()
{
	N=read();S=1<<N;
	reg int i,j;
	for(i=0;i<S;++i)a[i]=mp(read(),0);
	for(j=0;j<N;++j)for(i=0;i<S;++i)if(i>>j&1)
		a[i]=Merge(a[i],a[i^(1<<j)]);
	for(i=1;i<S;++i)ans=max(ans,a[i].fi+a[i].se),printf("%d\n",ans);
	return 0;
	return 0;
}