#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[405],b[405],dp[405][405];
int n;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
	{
        cin>>a[i];
        b[i]=a[i]+b[i-1];
    }
    for(int i=1;i<n;i++)
	{
        for(int j=1;i+j<=n;j++)
		{
            dp[j][j+i]=1e18;
            for(int k=j;k<i+j;k++)
                dp[j][j+i]=min(dp[j][j+i],dp[j][k]+dp[k+1][j+i]);
            dp[j][j+i] += (b[j+i]-b[j-1]);
        }
    }
    cout<<dp[1][n];
    return 0;
}