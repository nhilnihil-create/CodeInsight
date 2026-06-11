#include<bits/stdc++.h>
#define ll long long int
#define fin for(i=0;i<n;i++)
#define vec vector<ll>
#define pb push_back
#define vecit vector<ll>::iterator
#define vecp vector<pair<ll,ll> >
#define vecpit vector<pair<ll,ll> >::iterator
#define mapp map<ll,ll>
#define mapr map<ll,pair<ll,ll> >
#define maprit map<ll,pair<ll,ll> >::iterator
#define mapit map<ll,ll>::iterator
#define mod1 1000000007
#define INF 1000000000000000000
#define twodp vector<vector<ll> >dp(n+1,vec (k+1,0));
using namespace std;
int main()
{
    ll n,i,j,k,l;
    cin>>n>>k;
    twodp
    vec v;
    fin
    {
        cin>>j;
        v.pb(j);
    }
    for(i=0;i<=n;i++)
    {
        dp[i][0]=1;
    }
    for(i=1;i<=n;i++)
    {
        vec p;
        p.pb(1);
        for(l=1;l<=k;l++)
        {
            p.pb((dp[i-1][l]+p[l-1])%mod1);
        }
        for(j=1;j<=k;j++)
        {
            if(j<=v[i-1])
            {
                dp[i][j]=p[j];
            }
            else
            {
                dp[i][j]=(p[j]-p[j-v[i-1]-1]+mod1)%mod1;
            }
        }
    }
   /* for(i=0;i<=n;i++)
    {
        for(j=0;j<=k;j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<"\n";
   }
*/


    cout<<dp[n][k];



}
