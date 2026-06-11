#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[105];
long long f[105][100005];
long long INF=1e9  +7;
long long sum[105][100005];
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;++i)
	    scanf("%d",&a[i]);
	f[0][0]=1;
    for(int i=0;i<=k;++i)
       sum[0][i]=1;
	for(int i=1;i<=n;++i)
	{
		for(int j=0;j<=k;++j)
		{
			f[i][j]=sum[i-1][j] + INF; //a [i ] =2  j-1 j-2  
			if(j-a[i] > 0) f[i][j]-=sum[i-1][j-a[i]-1];
			f[i][j] %=INF;
			if(j>0) sum[i][j] = sum[i][j-1] +f[i][j];
			else sum[i][j]=f[i][j];
			sum[i][j] %=INF;
			//cout<<f[i][j]<<" "<<i<<" "<<j<<endl;
		}
	}
	printf("%lld\n",f[n][k]); 
	return 0;
}