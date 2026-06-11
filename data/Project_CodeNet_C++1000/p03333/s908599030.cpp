#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<climits>
#define lint long long
#define db double
#define debug(x) cerr<<#x<<"="<<x
#define sp <<" "
#define ln <<endl
#define N 100010
using namespace std;
int id[2][N],del[N],p[5];struct seg{int v[2];}s[N];
inline int Lcmp(int a,int b) { return s[a].v[0]>s[b].v[0]; }
inline int Rcmp(int a,int b) { return s[a].v[1]<s[b].v[1]; }
inline int gabs(int x) { return x<0?-x:x; }
int main()
{
//	freopen("data.in","r",stdin),freopen("std.out","w",stdout);
	int n;scanf("%d",&n);lint ans=0,t;
	for(int i=1;i<=n;i++) scanf("%d%d",&s[i].v[0],&s[i].v[1]);
	for(int i=1;i<=n;i++) id[0][i]=id[1][i]=i;
	sort(id[0]+1,id[0]+n+1,Lcmp),sort(id[1]+1,id[1]+n+1,Rcmp);
//	for(int i=1;i<=n;i++) debug(id[0][i])sp,debug(id[1][i])ln;
	for(int dir=0,x;dir<=1;dir++)
	{
		memset(del,0,sizeof(del)),p[0]=p[1]=1,t=x=0;
		for(int d=dir,i,q=1;max(p[0],p[1])<=n&&q<=3*n;d^=1,q++)
		{
			while(p[d]<=n&&del[id[d][p[d]]]) p[d]++;
			if(p[d]>n) break;i=id[d][p[d]];
			if(!d&&x>=s[i].v[0]) continue;
			if(d&&x<=s[i].v[1]) continue;
			del[i]=1,t+=gabs(s[i].v[d]-x),x=s[i].v[d];
//			debug(d)sp,debug(p[d])sp,debug(i)sp,debug(x)sp,debug(t)ln;
		}
		ans=max(ans,t+=gabs(x));
//		debug(t)ln;
	}
	return !printf("%lld\n",ans);
}