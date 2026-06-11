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
ll f[200000]={0};
ll mod=1000000007;
void ini()
{
   f[0]=1;
   for(ll i=1;i<=200000;i++)
   f[i]=(i*f[i-1])%mod;
}
void build(ll tree[],ll v,ll l,ll r,ll dp[])
{
   if(l==r)
      tree[v]=dp[l];
   else
   {
      ll m=(l+r)/2;
      build(tree,2*v,l,m,dp);
      build(tree,2*v+1,m+1,r,dp);
      tree[v]=max(tree[2*v],tree[2*v+1]);
   }
}
ll query(ll tree[],ll v,ll l,ll r,ll tl,ll tr)
{
   if(l==tl && tr==r)
   {
    //  cout<<"max of "<<tl<<" "<<tr<<" "<<tree[v]<<endl;
      return tree[v];
   }
   else
   {
      ll m=(l+r)/2;
      if(tr<=m)
      {
         ll z1= query(tree,2*v,l,m,tl,tr);
     //    cout<<"max of "<<tl<<" "<<tr<<" "<<z1<<endl;
         return z1;
      }
      else if(tl>m)
      {
         ll z2= query(tree,2*v+1,m+1,r,tl,tr);
      //   cout<<"max of "<<tl<<" "<<tr<<" "<<z2<<endl;
         return z2;
      }
      else 
      {
         ll z=query(tree,2*v,l,m,tl,m);
         ll z1=query(tree,2*v+1,m+1,r,m+1,tr);
       //  cout<<"max of "<<tl<<" "<<tr<<" "<<max(z1,z)<<endl;
         return max(z1,z);
      }
      
      
   }
}
void update(ll tree[],ll v,ll l,ll r,ll pos,ll element)
{
   if(l==r && l==pos)
   tree[v]=element;
   else
   {
      ll m=(l+r)/2;
      if(pos<=m)
      update(tree,2*v,l,m,pos,element);
      else
      update(tree,2*v+1,m+1,r,pos,element);
      tree[v]=max(tree[2*v],tree[2*v+1]);
   }
}

ll ncr(ll n,ll r)
{
   ll res=1;
   ll k=f[n];
   ll v=inverse(f[n-r],mod);
   ll u=inverse(f[r],mod);
   ll x=(u*v)%mod;
   k=(k*x)%mod;
   return k;
}
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
  ll n;
  cin>>n;
  ll h[n];
  ll a[n];
  for(ll i=0;i<2;i++)
  {
     for(ll j=0;j<n;j++)
     {
        if(i==0)
        cin>>h[j];
        else
        cin>>a[j];
     }
  }
ll dp[n+1]={0};
dp[0]=0;
ll tree[4*n+1];
build(tree,1,0,n,dp);
for(ll i=0;i<n;i++)
{
   ll s=query(tree,1,0,n,0,h[i]-1);
  // cout<<s<<endl;
   dp[h[i]]=max(dp[h[i]],a[i]+s);
   update(tree,1,0,n,h[i],dp[h[i]]);
}
cout<<query(tree,1,0,n,0,n)<<endl;
return 0;
}
