/* SHUBHAM KESHARWANI */
#include<bits/stdc++.h>
#define ll long long int
#define mod 1000000007
#define fr(a,b) for(ll i=a;i<b;i++)
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define test ll t; cin>>t; while(t--)
#define pb push_back
#define all(x) (x).begin(),(x).end()
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
using namespace std;
int main()
{fast;
//test
{
   ll n,k,i,j;
   cin>>n>>k;
   ll a[n];
   for(i=0;i<n;i++)
   cin>>a[i];
   ll dp[k+1]={0};
   for(i=1;i<=k;i++)
   {
       for(j=0;j<n;j++)
       {
           if(i>=a[j]&&dp[i-a[j]]==0)
           {
               dp[i]=1;
               break;
           }
       }
   }
   if(dp[k]==1)
   cout<<"First";
   else
   cout<<"Second";
cout<<'\n';
}
    return 0;
}