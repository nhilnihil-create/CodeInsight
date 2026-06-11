#include <iostream>
#include<bits/stdc++.h>

#define l long 
using namespace std;

int solve(int idx , int n , vector<vector<int>>&dp ,vector<vector<int>>&act , int check)
{

    if(idx >= n)
      return 0;
    
    if(dp[idx][check] != -1)
     return  dp[idx][check];

    int op1 = -1e7;
    int op2 = -1e7;
    int op3 = -1e7;
   
   if(check != 0)
    op1 = solve(idx+ 1, n , dp , act , 0) + act[idx][0];
   
   if(check != 1)
    op2 = solve(idx +1 , n , dp , act , 1) + act[idx][1];

    if(check != 2)
    op3 = solve(idx + 1, n , dp , act , 2)+ act[idx][2];


    dp[idx][check] = max(op1 ,max(op2 , op3));
    
    return dp[idx][check];
}

int main()
{
     

    int n;
    cin>>n;

    vector<vector<int>>act(n , vector<int>(3));
    for(int i = 0 ;i<n ;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        act[i][0] = a;
        act[i][1] = b;
        act[i][2] = c;
    }


    vector<vector<int>>dp(n +1 , vector<int>(4 , -1));

    int ans = solve(0 , n , dp , act , 3);
    /*for(int i = 0 ;i<n+1 ;i++)
    {
        for(int j = 0 ;j<4 ;j++)
         cout<<dp[i][j]<<" ";
        
        cout<<"\n";
    }*/
    cout<<ans<<endl;
    return 0;

}