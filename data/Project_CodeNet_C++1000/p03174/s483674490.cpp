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
    l n,cnt=0;
    cin>>n;
    l a[n][n];
    for(l i=0;i<n;i++)
    {
        for(l j=0;j<n;j++)
        {
            cin>>a[i][j];
        }
    }
    ll mask=1LL<<n,x=1LL;
    vector<ll> dp(mask);
    for(ll ms=0;ms<mask;ms++)
    {
        cnt=0;
        x=1LL;
        while(x<mask)
        {
            if((x&ms)!=0)
            cnt++;
            x<<=1;
        }
        if(cnt==0)
        {
            dp[ms]=1;
            continue;
        }
        for(l i=0;i<n;i++)
        {
            x=1LL<<i;
            if((x&ms)!=0)
            {
                if(a[i][cnt-1]==1)
                    dp[ms]=(dp[ms]+dp[(ms^x)])%MOD;
            }
        }
    }
    if(dp[mask-1]<0)
    dp[mask-1]+=MOD;
    cout<<dp[mask-1]<<endl;
}