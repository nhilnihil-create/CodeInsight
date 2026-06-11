#include <bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int n,f[3030][3030],sum[3030],ans;
string sa;
int main()
{
	cin>>n>>sa;
	f[1][1]=1;
	for(int i=2;i<=n;i++)
	{
		for(int j=0;j<=n;j++)
			sum[j]=(sum[j-1]+f[i-1][j])%mod;
		for(int j=1;j<=i;j++)
		{
			if(sa[i-2]=='<')
			{
				f[i][j]=sum[j-1];
			}
			else
				f[i][j]=(sum[i]+mod-sum[j-1])%mod;
//			cout<<f[i][j]<<endl;
		}
	}
	for(int i=1;i<=n;i++)
		ans=(ans+f[n][i])%mod;
	cout<<ans<<endl;
	return 0;
}