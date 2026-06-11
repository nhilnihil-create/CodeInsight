#pragma GCC optimize ("-O2")
#include <iostream>
#include <bits/stdc++.h>
#include <queue>
#include <stack>
#include <vector>
#define loop(n) for(ll i=0;i<n;i++)
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
typedef int ll;
const ll Mxn = 21;
const ll md = 1e9 + 7;
const ll Mxd = (1 << 21) + 2;

ll matrix[Mxn];
ll dp[Mxn][Mxd];


ll count(ll m,ll n,ll bitmask)
{
	if(m == n)
		return (__builtin_popcount(bitmask) == n);
	
	if(dp[m][bitmask] != -1)
	{
		return dp[m][bitmask];
	}
		
	ll res = 0;
	for(ll i=0;i<n;i++)
	{
		if(((1 << i) & matrix[m]) && !(bitmask & (1<<i)))
		{
			
			res = (res +  count(m+1,n,bitmask | (1<<i)))%md;
			
			
		}
		
	}
	dp[m][bitmask] = res;
	return res;
}



int main()
{
    //fastio;
    memset(dp,-1,sizeof(dp));
    
    ll n;
	cin>>n;
	for(ll i=0;i<n;i++)
	{
		matrix[i] = 0;
		for(ll j=0;j<n;j++)
		{
			int x;
			cin>>x;
			
			if(x)
			{
				matrix[i] |= (1LL << j);
			}
		}
		
	}
		
	
	
	ll res = count(0,n,0);
	cout<<res<<endl;
    
    return 0;
}
