#include<cstdio>
#include<algorithm>
int n,f[100005],x;
int solve(int x,int y){return std::max(x-y,y-x);}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&f[i]);
	std::sort(f+1,f+n+1);
	x=1;
	for (int i=1;i<=n;i++)
	    if (solve(f[i]*2,f[n])<solve(f[x]*2,f[n])) x=i;
	printf("%d %d\n",f[n],f[x]);
	return 0;
}