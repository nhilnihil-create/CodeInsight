#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
int main()
{
    ll n;
    cin>>n;
    string s;
    cin>>s;
    ll dp[n+1][n+1]={{0}};
  /*  for(ll i=0;i<n;i++)
    {
        for(ll j=0;j<=n;j++)
        cout<<dp[i][j]<<" ";
        cout<<endl;
    }*/
    for(ll i=0;i<n;i++)
    dp[0][i]=1;
    ll m=1000000007;
    for(ll i=1;i<n;i++)
    {
        if(s.at(i-1)=='>')
        {
          ll r=0;
          for(ll j=n-i-1;j>=0;j--)
          {
              r=(r+dp[i-1][j+1])%m;
              //cout<<"nh "<<dp[i-1][j+1]<<endl;
              //cout<<j<<" hjh "<<r<<endl;
              dp[i][j]=(dp[i][j]+r)%m;
          }
        }
        else
        {
            ll r=0;
            for(ll j=0;j<n-i;j++)
            {
                r=(r+dp[i-1][j])%m;
                //cout<<"no  "<<dp[i-1][j]<<endl;
                //cout<<j<<" yjh "<<r<<endl;
                dp[i][j]=(dp[i][j]+r)%m;

            }
        }
    }
    //for(ll i=0;i<n;i++)
    //{
      //  for(ll j=0;j<n-i;j++)
       // {
            //cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
        //}
    //}
    cout<<dp[n-1][0]<<endl;
    return 0;
}
    
       