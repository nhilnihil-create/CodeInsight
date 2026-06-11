#include <iostream>
#include<bits/stdc++.h>

#define l long 
using namespace std;

l solve(int idx , vector<int>&v , vector<l>&dp , int n ,int k)
{
    if(idx == n)
      return 0;
    
    if(dp[idx] != -1)
     return dp[idx];


    l omin = 1e12;


    for(int i = 1 ; i <= k && i + idx <= n ; i++)
    {
        l my = solve(idx + i , v , dp , n ,k) + abs(v[idx] - v[idx + i]);

        if(my < omin)
           omin = my;
    }
    dp[idx] = omin;

    return omin;
}
int main() {
    

    int n,k;
    cin>>n>>k;

    vector<int>v(n) ;

    for(int i = 0 ;i<n ;i++)
      cin>>v[i];

   
   vector<l>dp(n+1 , -1);

   l ans = solve( 0 , v , dp , n - 1 , k);

   cout<<ans<<endl;
}   
