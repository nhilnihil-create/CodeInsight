#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define pb push_back
#include <ext/pb_ds/assoc_container.hpp> // Common file  
#include <ext/pb_ds/tree_policy.hpp>  
#include <functional> // for less   
using namespace __gnu_pbds;  
using namespace std;  
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> set1;
ll find(ll a,ll p[])
{
   //cout<<"find "<<a<<endl;
   if(a==p[a])
   return a;
   else return p[a]=find(p[a],p);

}
void join(ll a,ll b,ll p[],ll sz[])
{
   a=find(a,p);
   b=find(b,p);
   if(a!=b)
   {
      if(sz[a]<sz[b])
      swap(a,b);
      sz[a]+=sz[b];
      p[b]=a;
   }
}
ll power(ll a,ll b,ll mod)
{
   ll res=1;
   while(b>0)
   {
      if(b&1)
      res=(res*a)%mod;
      b=b/2;
      a=(a*a)%mod;
   }
   return res;
}
ll inverse(ll x, ll p)
{
   return power(x,p-2,p);
}
ll hash1(ll x,ll y)
{
   return x+y+x*y;
}
//ll f[200000]={0};
ll mod=1000000007;
/*void ini()
{
   f[0]=1;
   for(ll i=1;i<=200000;i++)
   f[i]=(i*f[i-1])%mod;
}*/



/*ll ncr(ll n,ll r)
{
   ll res=1;
   ll k=f[n];
   ll v=inverse(f[n-r],mod);
   ll u=inverse(f[r],mod);
   ll x=(u*v)%mod;
   k=(k*x)%mod;
   return k;
}*/
/*struct edge
{
   ll from;
   ll to;
};*/
ll f1(ll mask,ll dp[],ll m[][22],ll n)
{
  //   cout<<"mask "<<mask<<endl;
    ll ones=__builtin_popcountll(mask);
    if(dp[mask]!=-1)
    return dp[mask];
    else if(ones==1)
    {
        ll ind;
        for(ll i=0;i<n;i++)
        {
            ll powerof2=1<<i;
          //  cout<<"power "<<powerof2<<" mask "<<mask<<endl;
            ll z=mask&powerof2;
        //    cout<<" and result "<<z<<endl;
            if(z)
            {
                ind=i;
                break;
            }
        }
     //   cout<<ind<<endl;
        
        if(m[0][ind]==1)
        dp[mask]=1;
        else
        dp[mask]=0;
        return dp[mask];
    }
    else
    {
        dp[mask]=0;
    for(ll i=0;i<n;i++)
    {
        
        ll powerof2=1<<i;
       // ll p=__builtin_popcount(mask);
       ll u=powerof2&mask;
        if(u && m[ones-1][i])
        {
            ll submask=mask^powerof2;
            dp[mask]+=f1(submask,dp,m,n);
            dp[mask]=(dp[mask]%mod);
        }
    }
    return dp[mask];
    }
}


int main()
{
   ios_base::sync_with_stdio(false);
    cin.tie(NULL);
   ll n;
   cin>>n;
   ll a[22][22];
   for(ll i=0;i<n;i++)
   {
      for(ll j=0;j<n;j++)
      cin>>a[i][j];
   }
  // cout<<"here "<<endl;
   ll z=(ll)pow(2,n);
  // cout<<z<<endl;
   ll dp[z]={0};
   for(ll i=0;i<z;i++)
   dp[i]=-1;
   cout<<f1(z-1,dp,a,n)<<endl;
  // ll m=1<<5;
   //cout<<m<<endl;
   return 0;
}