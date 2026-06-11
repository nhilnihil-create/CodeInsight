#define dbg(...) ; 
#define db(...) ; 
#include "bits/stdc++.h"
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define f(i,a,b) for(i=a;i<b;i++)
#define fr(i,a,b) for(i=a;i>=b;i--)
#define endl '\n'
#define tst cout<<'*';
#define ll long long int
#define ff first
#define ss second
#define pb push_back
#define pf push_front
#define mod 1000000007
using namespace std;
 
int n,k,ar[105],dp[100005][2],mn;

int fun(int rem, int x)
{
    dbg(rem,x);
    int i;
    if(rem<mn)
        return (x+1)%2;
    if(dp[rem][x]!=-1)
        return dp[rem][x];

    dp[rem][x]=(x+1)%2;

    f(i,0,n)
    {
    	if(ar[i] <= rem){
        	dp[rem][1]=max(dp[rem][1],fun(rem-ar[i],0));
        	dp[rem][0]=min(dp[rem][0],fun(rem-ar[i],1));
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
    db(dp,0,k,0,2);
}