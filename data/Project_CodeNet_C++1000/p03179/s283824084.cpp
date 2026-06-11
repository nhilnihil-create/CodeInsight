#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define endl '\n'
#define pb push_back
#define mod 1000000007
#define mp make_pair
#define pi acos(-1)
#define line cout<<"----------------------------"<<endl
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL)
#define filein freopen("input.txt","r",stdin)
#define fileout freopen("output.txt","w",stdout)
using namespace std;
const ll  mx=3009;
ll  n ;
string str; 
ll  dp[mx][mx]; ///number of way to solve upto prefix i when last digit is j
ll sum[mx]; 
int   main()
{
	cin>>n>>str; 
	dp[1][1]=1; 
	sum[1]=1 ; 
	for(ll  i=2;i<=n;i++)
	{
		for(ll  last=1;last<=i;last++)
		{
			int suru,ses; 
			if(str[i-2]=='<')
			{
				suru=1; ses=last-1; 
			}
			else 
			{
				suru=last; ses=i-1; 
			}
			ll rem=(sum[ses]-sum[suru-1])%mod  ; 
			rem=(rem+mod)%mod; 
			dp[i][last]+=rem;  
			dp[i][last]%=mod; 
		}

		for(int j=1;j<=i;j++) sum[j]=sum[j-1]+dp[i][j],sum[j]%=mod; 
	}
	ll  ans=0;
	for(ll  i=1;i<=n;i++)
	{
		ans+=dp[n][i]; 
		ans%=mod; 
	}
	cout<<ans<<endl; 
	
}
