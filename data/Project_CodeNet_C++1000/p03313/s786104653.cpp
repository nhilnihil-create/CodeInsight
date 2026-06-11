#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;
typedef long long ll;
struct ee{
	int fi,se;
}p[524290];
int n,a[524290],N,ans;
void f(int x,int y)
{
	if(x==p[y].fi||x==p[y].se) return;
	if(a[x]>a[p[y].fi]) p[y].se=p[y].fi,p[y].fi=x;
	else if(a[x]>a[p[y].se]) p[y].se=x;
}
int main()
{
	scanf("%d",&n);
	N=1<<n;
	for(int i=0;i<N;i++) scanf("%d",&a[i]),p[i].fi=i,p[i].se=N;
	for(int i=1,j,ls,now;i<N;i++)
	{
		ls=i;
		j=(i-1)&i;
		for(;ls;)
		{
				int k=i^(ls-j);
				f(p[k].fi,i);
				f(p[k].se,i);
				ls=j;
				j=(j-1)&j;
		}
	}
	for(int i=1;i<N;i++)
	{
		ans=max(ans,a[p[i].fi]+a[p[i].se]);
		printf("%d\n",ans);
	}
}