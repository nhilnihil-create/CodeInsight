#include <bits/stdc++.h>
#include <set>
#define ll long long 
#include <string>
#define pb push_back
#define mp make_pair
# define pi 3.14159265358979323846
#define mod 1000000007
#define rep(i,n) for(i=0;i<n;i++)
#define rep1(i,n) for(i=1;i<n;i++)
using namespace std;
void fastio()
{
	#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

}
ll int multiply(ll int a,ll int b)
{
	ll int ans=(a%mod*b%mod)%mod;
	return ans;
}
ll int add(ll int a, ll int b)
{
	ll int ans=(a%mod+b%mod)% mod;
	return ans;
}
 
void solve()
{
	string s,t;
	cin>>s>>t;
	ll int n=s.size();
	ll int m=t.size();
	ll int dp[n+1][m+1];
	memset(dp,0,sizeof dp);
	ll int i,j;
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=m;j++)
		{
			if (i==0 || j==0)
				dp[i][j]=0;
			else
			{
				if (s[i-1]==t[j-1])
					dp[i][j]=1+dp[i-1][j-1];
				else
				{
					ll int op1=dp[i-1][j];
					ll int op2=dp[i][j-1];
					dp[i][j]=max(op1,op2);
				}
			}
		}
	}
	// rep(i,n+1)
	// {
	// 	rep(j,m+1)
	// 	cout<<dp[i][j]<<" ";
	// 	cout<<endl;
	// }
	string ans="";
	// cout<<ans<<endl;
	i=n,j=m;
	while(i>0 && j>0)
	{
		if (dp[i][j]==dp[i-1][j])
		{
			i--;
		}
		else if (dp[i][j]==dp[i][j-1])
		{
			j--;
		}
		else
		{
			ans+=s[i-1];
			i--;
			j--;
		}

	}
	reverse(ans.begin(),ans.end());
	cout<<ans<<endl;


}

int main()
{ 
	fastio();
    ll int t;
    // cin>>t;
    t=1;
    while(t--)
    {
    	solve();
    }
}

	
		
	
	
	
	



