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
    string s1,s2;
    cin>>s1>>s2;
    ll n=s1.length();
    ll m=s2.length();
    ll dp[n+1][m+1];
    memset(dp,0,sizeof(dp));
    for(ll i=0;i<n;i++)
    {
        for(ll j=0;j<m;j++)
        {
            if(s1[i]==s2[j])
            {
                dp[i+1][j+1]=dp[i][j]+1;
            }
            else
            {
                dp[i+1][j+1]=max(dp[i][j+1],dp[i+1][j]);
            }
        }
    }
    string ans="";
    ll i=n,j=m;
    while(i>0&&j>0)
    {
        if(dp[i][j]>dp[i-1][j]&&dp[i][j]>dp[i][j-1])
        {
            ans=ans+s1[i-1];
            i--;
            j--;

        }
        else
        {
            if(dp[i-1][j]>dp[i][j-1])
            {
                i--;
            }
            else
            {
                j--;
            }
        }
    }
    reverse(ans.begin(),ans.end());
    cout<<ans<<endl;

}
