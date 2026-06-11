// coded by zeffy
#pragma GCC optimize("O3","unroll-loops","omit-frame-pointer","inline") //Optimization flags
#pragma GCC option("arch=native","tune=native","no-zeroupper") //Enable AVX
#pragma GCC target("avx","popcnt")  //Enable AVX
#include <x86intrin.h> //SSE Extensions
#include <bits/stdc++.h> 
using namespace std;
#define eb emplace_back
#define mp make_pair
#define hello cout<<"hello"<<"\n"
#define forr(i,a,b) for(int i=a;i<b;i++)
#define it(s)	for(auto itr:s)
#define dvg(s) 	for(auto itr:s)	cout<<itr<<" ";cout<<endl;
#define dbg(s)	cout<<#s<<"= "<<s<<endl;
typedef long long int lli;
typedef unsigned long long int ulli;
const lli INF=(lli)1e17+5;
const ulli MOD=1e8+7;

int main()
{
   int n,k;cin>>n>>k;
   lli h[n];
   forr(i,0,n) cin>>h[i];

   lli dp [n];memset(dp,INF,sizeof(dp));
   
   dp[0]=0;dp[1]=abs(h[1]-h[0]);
   forr(i,0,n)
   {
      for(int j=max(0,i-k);j<i;j++)
      {
         dp[i]=min(dp[i],abs(h[i]-h[j])+dp[j]);
      }
   }
   
   cout<<dp[n-1]<<"\n";
   return 0;
}
   
