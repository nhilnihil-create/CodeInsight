#include<iostream>
#include<climits>
using namespace std;
#define ll long long int
ll arr[100001];
ll dp[100001];

int solve(int n,int k)
{
    dp[1]=0;
    //dp[2]=abs(arr[2]-arr[1]);
   ll m=0;
    
    for(ll i=2;i<=n;i++)
    {   
    	ll ans =INT_MAX;
        for(int j=1;j<=k;j++)
        {
        	if(i>j)
        	{
        		 m=dp[i-j]+abs(arr[i]-arr[i-j]);
        		ans = min(ans,m);
        	}
        }
        dp[i]=ans;
    }
   // for(int i=1;i<=n;i++)  cout<<dp[i]<<endl;

      return dp[n];

}
int main()
{
    ll n;  cin>>n;
    ll k; cin>>k;
    
    for(int i=1;i<=n;i++)  cin>>arr[i];

    cout<<solve(n,k)<<endl;
}
