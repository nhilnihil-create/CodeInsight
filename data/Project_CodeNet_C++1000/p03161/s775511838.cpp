

#include <bits/stdc++.h>

using namespace std;


#define ll              long long
#define pb              push_back
#define nn           cout << "\n";



int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t,a,b,i,j,c,d,e,f,n,k,m,w;



    cin>>n>>k;

      int dp[n+5],ht[n+5];

    for(i=1;i<=n;i++)
    {
        cin>>a;
        ht[i]=a;

    }

    dp[n]=0;
    for(i=n-1;i>=1;i--)
    {
        dp[i]=1000000000;
        for(j=1;j<=k&&(i+j)<=n;j++)
        {


        dp[i]=min(dp[i],(dp[i+j]+abs(ht[i]-ht[i+j])));
        }
    }

    cout<<dp[1]<<endl;
    return 0;
}