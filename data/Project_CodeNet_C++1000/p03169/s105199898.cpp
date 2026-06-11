#include<iostream>
#include<cstdio>
using namespace std;
double dp[305][305][305];
int main()
{
	int n;cin>>n;
	int n1=0,n2=0,n3=0;
	for(int i=1;i<=n;i++)
	{
		int x;cin>>x;
		if(x==1)n1++;
		else if(x==2)n2++;
		else n3++;
	}
	for(int k=0;k<=n3;k++)
		for(int j=0;j<=n3+n2;j++)
			for(int i=0;i<=n3+n2+n1;i++)
			{
				if(i==0&&j==0&&k==0){dp[i][j][k]=0;continue;}
				dp[i][j][k]=1.0*(n)/(i+j+k);
    			if(i)dp[i][j][k]+=(1.0*i/(i+j+k))*dp[i-1][j][k];
    			if(j)dp[i][j][k]+=(1.0*j/(i+j+k))*dp[i+1][j-1][k];
    			if(k)dp[i][j][k]+=(1.0*k/(i+j+k))*dp[i][j+1][k-1];
			}
	printf("%.10lf",dp[n1][n2][n3]);
	return 0;
}