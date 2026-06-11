#include <bits/stdc++.h>
using namespace  std;
const int N=3e3+10;
double f[N][N],p[N];
int n;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%lf",&p[i]);
	f[0][0]=1,f[1][0]=1.0-p[1];
	double ans=0.000000000;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=i;j++)
		{
			if(!j)f[i][j]=f[i-1][j]*(1-p[i]);
			f[i][j]=f[i-1][j-1]*p[i]+f[i-1][j]*(1.0-p[i]);

		}
	}
	for(int i=n/2+1;i<=n;i++)ans+=f[n][i];
	printf("%.10f",ans);
    return 0;
}
