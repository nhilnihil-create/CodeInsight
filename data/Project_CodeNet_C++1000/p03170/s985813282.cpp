
#include "bits/stdc++.h"
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define f(i,a,b) for(i=a;i<b;i++)
using namespace std;
 
int n,k,ar[105],dp[100005][2],mn;

int fun(int rem, int x)
{
    int i;
    if(rem<mn)
        return dp[rem][x] = x^1;
    if(dp[rem][x]!=-1)
        return dp[rem][x];

    dp[rem][x]=x^1;

    f(i,0,n)
    {
    	if(ar[i] <= rem){
    		if(x)
        		dp[rem][x] |= fun(rem-ar[i],x^1);
        	else
        		dp[rem][x] &= fun(rem-ar[i],x^1);
   		}
    }
    return dp[rem][x];
}

int main()
{
    fast;
    int i;
    cin>>n>>k;
    f(i,0,n)
        cin>>ar[i];
    mn=*min_element(ar,ar+n);
    memset(dp,-1,sizeof(dp));
    (fun(k,1))?cout<<"First":cout<<"Second";
}