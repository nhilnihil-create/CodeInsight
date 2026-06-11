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
#define INF 10000000000
using namespace std;
int main()
{
   ll n,k;
   cin>>n>>k;
   vec v;
   ll i,j,p,q,l;
   fin
   {
       cin>>j;
       v.pb(j);
   }
   sort(v.begin(),v.end());
   vec dp(k+1);
   dp[0]=0;
   for(i=1;i<v[0];i++)
    dp[i]=2;
    p=v[0];
    ll f;
   for(i=p;i<=k;i++)
   {
       f=0;
       for(j=0;j<n;j++)
       {
           q=v[j];
           if(q>i)
            break;
           if(dp[i-q]==0)
            f=1;
           else if(dp[i-q]==2)
            f=1;
       }
       if(f==0)
        dp[i]=2;
       else
        dp[i]=1;
   }
   if(dp[k]==1)
    cout<<"First";
   else
    cout<<"Second";


}
