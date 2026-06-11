#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[3005][3005],a[3005],ans=0ll;
const ll MOD=1e9+7ll;
int n;
string s;
int main()
{
    cin>>n>>s;
    dp[1][1]=1;
    for(int i=2;i<=n;i++)
    {
        for(int j=1;j<i;j++)
            a[j]=(a[j-1]+dp[i-1][j])%MOD;
        for(int j=1;j<=n;j++)
        {
            int l,r;
            if(s[i-2]=='<')
            {
            	l=1;
				r=j-1;
			}
            else
            {
            	l=j;
            	r=i-1;
			}
            if(l<=r)dp[i][j]=(dp[i][j]+a[r]-a[l-1]+MOD)%MOD;
        }
    }
    for(int i=1;i<=n;i++)
    {
    	ans+=dp[n][i];
    	ans%=MOD;
	}
    cout<<ans<<endl;
	return 0;
}