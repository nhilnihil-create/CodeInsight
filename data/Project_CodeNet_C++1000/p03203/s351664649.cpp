#include<bits/stdc++.h>
#define to edge[i].v
#define mp make_pair
#define rint register int
#define debug(x) cerr<<#x<<"="<<x<<endl
#define fgx cerr<<"-------------"<<endl
#define N 1000000
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
struct P{int x,y;}a[N]; int f[N];
inline bool cmp(P x,P y){return x.y==y.y?x.x<y.x:x.y<y.y;}
int main()
{	int n,m,k,ans=1e9;cin>>n>>m>>k;
	for(rint i=1;i<=k;i++) scanf("%d%d",&a[i].x,&a[i].y);
	sort(a+1,a+k+1,cmp); f[1]=1;
	for(rint i=1,j=1,p=1;i<=m;i++)
	{	int st=f[i];
		while(j<=k&&a[j].y<=i) j++;
		while(j<=k&&a[j].y==i+1&&a[j].x<=f[i]) j++;
	//	debug(a[i].x);debug(a[i].y);
		while(j<=k&&a[j].y==i+1&&a[j].x==f[i]+1) f[i]++,j++;
		while(p<=k&&a[p].y==i){if(a[p].x>st)
		{	ans=min(ans,st-1+a[p].x-st-1);
	//		if(i==2) debug(a[p].x);
		}
	//	debug(a[p].x);debug(a[p].y);
		p++;}
		f[i+1]=f[i]+1; ans=min(ans,st-1+n-st);
	//	debug(f[i]);
	//	debug(i);debug(n);debug(st);debug(ans);fgx;
	}
	cout<<ans+1;
	return 0;
}
