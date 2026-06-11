#include<bits/stdc++.h>

using namespace std;
const int MAXN=310;
double dp[MAXN][MAXN][MAXN];

int a,b,c,n;

int main()
{
	cin>>n;
	for(int i=1,x;i<=n;++i)
	{
		cin>>x;
		if(x==1) ++a;
		if(x==2) ++b;
		if(x==3) ++c;
	}
	
	for(int k=0;k<=n;++k)
		for(int j=0;j<=n;++j)
			for(int i=0;i<=n;++i)
			{
				if(i||j||k)
				{
					if(i) dp[i][j][k]+=dp[i-1][j][k]*1.0*i/(i+j+k);
					if(j) dp[i][j][k]+=dp[i+1][j-1][k]*1.0*j/(i+j+k);
					if(k) dp[i][j][k]+=dp[i][j+1][k-1]*1.0*k/(i+j+k);
					dp[i][j][k]+=(double)n/(i+j+k);
				}

			}
		  
	cout<<fixed<<setprecision(11)<<dp[a][b][c]<<endl;
	
	
	
	return 0;
}
