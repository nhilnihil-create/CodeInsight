#include <iostream>
#include<bits/stdc++.h>

#define ll long long
using namespace std;
const int kmod = 1e9 + 7;
double ans = 0;


double solve(int idx ,int h ,vector<double>& coins , vector<vector<double>>&dp ,int n )
{
    if(idx == n)
    {
        int t = n - h;
        if( h > t)
         return 1.0;
        return 0.0;
    }
    
    if(dp[idx][h] != -1)
     return dp[idx][h];
    
    double my = 0;
     
     my = solve(idx + 1 , h + 1 , coins , dp , n  )*coins[idx] ;

    my = my + solve(idx + 1 , h , coins , dp , n )*(1 - coins[idx]);
   
    
    return dp[idx][h] = my;

}
int main()
{
    
   
   int n;
   cin>>n;
   
   vector<double>coin(n);

   vector<vector<double>>dp(n+1 , vector<double>(n+1 ,-1));

   for(int i = 0; i<n ;i++)
   cin>>coin[i];

    double ans = solve(0 , 0 , coin , dp , n);
   
   
   printf("%.9lf\n" ,ans);
   
}
