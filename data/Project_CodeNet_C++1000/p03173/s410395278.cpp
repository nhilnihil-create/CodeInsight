#include<bits/stdc++.h>
#define l long 
#define ll long long 
#define ld long double 
#define INF 1000000000000000
#define MOD 1000000007
#define MAX_N 1000006
#define f first
#define s second
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULLL);
using namespace std;
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    l n;
    cin>>n;
    vector<ll> a;
    ll x;
    for(l i=0;i<n;i++)
    {
        cin>>x;
        a.push_back(x);
    }
    ll prf[n],suf[n];
    prf[0]=a[0];
    for(l i=1;i<n;i++)
    {
        prf[i]=prf[i-1]+a[i];
    }
    suf[n-1]=a[n-1];
    for(l i=n-2;i>=0;i--)
    {
        suf[i]=suf[i+1]+a[i];
    }
    ll dp[n][n],sum=0LL;
    for(l i=0;i<n;i++){
        for(l j=0;j<n;j++)
        dp[i][j]=INF;
    }
    for(l len=1;len<=n;len++)
    {
        for(l i=0;i<n;i++)
        {
            if(i+len-1>=n)
            break;
            if(len==1)
                dp[i][i]=0;
            else 
            {
                sum=prf[n-1];
                if(i>0)
                sum-=prf[i-1];
                if(i+len<n)
                sum-=suf[i+len];
                for(l j=i;j<i+len-1;j++)
                {
                    dp[i][i+len-1]=min(dp[i][j]+dp[j+1][i+len-1]+sum,dp[i][i+len-1]);
                }
            }
        }
    }
    cout<<dp[0][n-1]<<endl;
}