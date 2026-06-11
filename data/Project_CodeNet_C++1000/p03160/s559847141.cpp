
#include <bits/stdc++.h>

using namespace std;


#define ll              long long
#define pb              push_back
#define nn           cout << "\n";


ll dp[100000],ht[100000];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t,a,b,i,j,c,d,e,f,n,k,m,w;

    memset(dp,0,sizeof(dp));

    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>a;
        ht[i]=a;

    }

    dp[n]=0;dp[n+1]=10000000;ht[n+1]=10000000;
    for(i=n-1;i>=1;i--)
    {
        
        dp[i]=min((dp[i+1]+abs(ht[i]-ht[i+1])),(dp[i+2]+abs(ht[i]-ht[i+2])));
    }

    cout<<dp[1];
    return 0;
}
