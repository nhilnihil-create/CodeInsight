#include <iostream>
#include<bits/stdc++.h>

using namespace std;

int solve(int idx , vector<int>&v , vector<int>&dp , int n)
{
    if(idx == n)
      return 0;
    
    if(dp[idx] != -1)
      return dp[idx];
    int op1 = INT_MAX;
    int op2 = INT_MAX;
    if(idx + 1 <= n)
    {
        op1 = solve( idx + 1 , v , dp , n) + abs(v[idx] - v[idx+1]);
    }
    if(idx + 2 <= n)
    {
        op2 = solve(idx + 2 , v , dp , n) + abs(v[idx] - v[idx+2]);
    }

    dp[idx] = min(op1 , op2);

    return dp[idx];
}
int main() {
    

    int n;
    cin>>n;

    vector<int>v(n) ;

    for(int i = 0 ;i<n ;i++)
      cin>>v[i];

   
   vector<int>dp(n+1 , -1);

   int ans = solve( 0 , v , dp , n - 1);

   cout<<ans<<endl;
}   
