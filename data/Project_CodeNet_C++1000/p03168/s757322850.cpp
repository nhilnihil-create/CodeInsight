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
   ll n;
   cin>>n;
   double ar[n];
   double ans=1;
   for(ll i=0;i<n;i++)
   {
       cin>>ar[i];
   }
   vector<vector<double>> v(n+1, vector<double>(n+1));
   v[0][0]=1.000000000;
   for(ll i=1;i<=n;i++)
   {
       for(ll j=0;j<=n;j++)
       {
           if(j==0)
            v[i][j]=(1-ar[i-1])*v[i-1][j];
           else
            v[i][j]=(ar[i-1]*v[i-1][j-1])+(1-ar[i-1])*v[i-1][j];
       }
   }
   cout<<fixed<<setprecision(10)<<accumulate(v[n].begin()+(n/2)+1,v[n].end(),0.0);

}
