#include <iostream>
#include<bits/stdc++.h>

#define ll long long
using namespace std;
const int kmod = 1e9 + 7;


int solve(int r ,int c , int rs ,int cs , vector<vector<int>>& dp ,vector<vector<char>> &board)
{
    if(r == rs  && c == cs)
     return 1;
    

    if(board[r][c] == '#')
     return 0;
    
    if(dp[r][c] != -1)
     return dp[r][c];

     int my = 0;
    if(r + 1 <= rs)
    my = (my % kmod + solve(r+1 , c , rs , cs ,dp , board)%kmod )%kmod ;

    if(c + 1 <= cs)
    my = (my % kmod + solve(r , c+1 , rs , cs ,dp , board) %kmod )%kmod;

    dp[r][c] = my;

    return my;
}
int main()
{
    
   int rs,cs;

   cin>>rs>>cs;


   vector<vector<char>>board(rs , vector<char>(cs));

   for(int i =0 ;i<rs ;i++)
   {
       for(int j = 0 ; j< cs ;j++)
        cin>>board[i][j];
   }
    
    vector<vector<int>>dp( rs , vector<int>( cs , -1));
   int ans = solve( 0 , 0 , rs -1 , cs -1, dp , board );

   cout<<ans<<endl;
}