#include<bits/stdc++.h>
#define l long 
#define ll long long 
#define ld long double 
#define INF 1000000000000
#define MOD 1000000007
#define MAX_N 1000006
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    l n,k;
    cin>>n>>k;
    vector<l> a;
    l x;
    for(l i=0;i<n;i++)
    {
        cin>>x;
        a.push_back(x);
    }
    vector<ll> dp(k+1),prf(k+1);
    dp[0]=1;
    l lo,hi;
    for(l i=0;i<n;i++)
    {
        for(l s=0;s<=k;s++)
            prf[s]=0;
        for(l s=0;s<=k;s++)
        {
            lo=s+1;
            hi=s+min(a[i],k-s);
            if(lo<=hi)
            {
                prf[lo]=(prf[lo]+dp[s])%MOD;
                if(hi<k)
                prf[hi+1]=(prf[hi+1]-dp[s])%MOD;
            }
        }
        dp[0]=(dp[0]+prf[0])%MOD;
        for(l s=1;s<=k;s++)
        {
            prf[s]=(prf[s-1]+prf[s])%MOD;
            dp[s]=(dp[s]+prf[s])%MOD;
        }
    }    
    if(dp[k]<0)
    dp[k]+=MOD;
    cout<<dp[k]<<endl;
}