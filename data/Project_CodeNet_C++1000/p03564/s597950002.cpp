#include <bits/stdc++.h>
#define ll long long int
#define fast ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)

using namespace std;



int _gcd(int a,int b)
{
	return (b==0?a:_gcd(b,a%b));
}
bool cmp(int a,int b)
{
	return a>b;
}

int main()
{
	fast;
	#ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
	    freopen("output.txt", "w", stdout);
	#endif
	    int n;cin>>n;
	    int k;cin>>k;
	    vector<int> dp(n+1);
	    dp[0]=1;
	    for(int i=1;i<=n;++i)
	    {
	    	dp[i]=min(dp[i-1]*2,dp[i-1]+k);
			
		}
		cout<<dp[n]<<endl;	

	return 0;
	    
}
