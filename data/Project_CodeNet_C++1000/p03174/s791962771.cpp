
#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define mp make_pair
#define size (1<<21)
using namespace std;
int a[22][22];
ll dp[22][size+1];
ll solve(int i,ll no,int n)
{
	if(i>n)
	return 1;
   // auto p=mp(i,x);
	if(dp[i][no]!=-1)
	return dp[i][no];
	ll ans=0;
	for(int k=1;k<=n;k++)
	{
        ll mask=1<<(k-1);
        if(a[i][k]==1 && (no&mask))
        {
            no-=mask;
            ans=(ans+solve(i+1,no,n))%mod;
            no+=mask;
        }

	}
	return dp[i][no]=ans;
}
int main() {
    int n;
    cin>>n;
    
    //set<int> x;
    ll no=(1<<n)-1;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
            cin>>a[i][j];
        //x.insert(i);
    }
    memset(dp,-1,sizeof(dp));
    
    ll ans=0;
    for(int i=1;i<=n;i++)
    {
    	if(a[1][i]==1)
    	{
            no-=1<<(i-1);
    		ans=(ans%mod+solve(2,no,n)%mod)%mod;
            no+=1<<(i-1);
            //x.insert(i);
    		//col[i]=false;
		}
	}
	cout<<ans;
}
