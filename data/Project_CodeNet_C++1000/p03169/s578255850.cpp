#include <iostream>
#include <bits/stdc++.h>
#include <queue>
#include <stack>
#include <vector>
#define loop(n) for(ll i=0;i<n;i++)
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
typedef long long int ll;

double dp[310][310][310];
ll n;

double solve(ll a,ll b,ll c)
{
	if(a == 0 && b == 0 && c == 0)
		return 0.0;
	
	if(dp[a][b][c] != -1)
		return dp[a][b][c];
	
	double curr = 1.0*n/(a + b + c);
	
	if(a)
	{
		curr += solve(a-1,b,c)*(1.0*a/(a + b + c));
	}
	if(b)
	{
		curr += solve(a+1,b-1,c)*(1.0*b/(a + b + c));
	}
	if(c)
	{		
		curr += solve(a,b+1,c-1)*(1.0*c/(a + b + c));
	}
	
	
	dp[a][b][c] = curr;

	return dp[a][b][c];
}
	
	

int main()
{
    fastio;
    //preset
    for(ll i=0;i<=305;i++)
		for(ll j=0;j<=305;j++)
			for(ll k=0;k<=305;k++)
				dp[i][j][k] = -1;
    
    
    cin>>n;
    ll arr[n];
    ll a = 0;
    ll b = 0;
    ll c = 0;
    for(ll i=0;i<n;i++)
    {
		cin>>arr[i];
		if(arr[i] == 1)
			a++;
		else if(arr[i] == 2)
			b++;
		else
			c++;
	}
	
	double ans = solve(a,b,c);
	cout<<setprecision(14);
	cout<<fixed<<ans<<endl;
	
	
	
	
    return 0;
    
}
