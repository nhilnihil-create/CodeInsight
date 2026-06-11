#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; ++i)
#define ALL(v) v.begin(), v.end()
typedef long long ll;
const int MOD = 1000000007;
const int INF = 1000000000;

ll fac[201];
ll dp[201][176];//dp[i][j]iまでの素数の積でj個の約数をもつ積の数・。・？

int main()
{

   int n;
   cin >> n;
   if(n<10){cout<<0<<endl;return 0;}
   for(int i = 2;i<=n;i++)
   {
      int K = i;
      int k=K;
      for(int j = 2;j*j<=K;j++)
      {
         while(K%j==0)
         {
            fac[j]++;
            K/=j;
         }
      }
      if(K!=1)fac[K]++;
   }
   vector<int> fac2;
   rep(i,101)
   {
      if(fac[i]!=0)fac2.push_back(fac[i]);
   }
   dp[0][1]=1;
   rep(i,fac2[0])
   {
      if(i<74)dp[0][i+2]=1;
   }

   for(int i = 0;i<fac2.size()-1;i++)
   {
      for(int j =0;j<= fac2[i+1];j++)
      { 
         for(int k = 1;k<76;k++)
         {
            if(k*(j+1)<76)
            dp[i+1][(k)*(j+1)]+=dp[i][k];
         }
      }
   }

   cout<<dp[fac2.size()-1][75]<<endl;
   return 0;
}