#include <bits/stdc++.h>
#include <fstream>
#include <iostream>
using namespace std;
#define ll long long int
#define pb push_back
#define mp make_pair
#define maxim INT_MAX
#define fi first
#define se second
#define INF 1e16
#define mod 1000000007
/* 1. If you can't keep solution in mind, then visualize it on a paper.
 * 2. Try to identify the type of problem - DP, Greedy, Graph, Constructive,
 * 	  Prefix/Suffix, Difference Array, BIT/Segment Tree, etc.
 * 3. Look at the problems from different perspectives - reverse the problem,
 * 	  add instead of delete (maybe?)
 * 4. Divide difficult solutions into cases and/or sequences.
 * 5. Use math rules to solve Nested Summation.
 * 6. Optimisation problems are generally solved with DP, greedy, binary search or brute-force.
 * 7. Try fixing a solution then proving we can't do better or worse than that.
 * ------------------------------------------------------------------
 */
int main()
{
   ll n,m;
   cin>>n>>m;
   ll dp[n+1][m+1];
   memset(dp,0,sizeof(dp));
   char ar[n][m];
   for(ll i=0;i<n;i++)
    cin>>ar[i];
   for(ll i=1;i<=m;i++)
   {
       if(ar[0][i-1]!='#')
       dp[1][i]=1;
       else
        break;
   }
   for(ll i=1;i<=m;i++)
   {
       if(ar[i-1][0]!='#')
       dp[i][1]=1;
       else
        break;
   }
   for(ll i=2;i<=n;i++)
   {
       for(ll j=2;j<=m;j++)
       {
           if(ar[i-1][j-1]!='#')
           {
               dp[i][j]=(dp[i-1][j]+dp[i][j-1])%mod;
           }
       }
   }
   cout<<dp[n][m]<<endl;
}
