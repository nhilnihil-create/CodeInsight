#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
/*int recur(vector<vector<char>>& arr,vector<vector<int>>& dp,int i,int j)
{
    if(i==arr.size() || j==arr[0].size())
    return 0;
    if(i==0 and j==0 and arr[i][j]=='#')
    return 0;
    if(dp[i][j]!=1)
    return dp[i][j];
    if(arr[i][j]=='#')
    {
         dp[i][j]=0;
    }
    else
   return  dp[i][j]=recur(arr,dp,i+1,j)+recur(arr,dp,i,j+1);
    
}*/
int main(){
    int h,w;
    cin>>h>>w;
    char arr[h+1][w+1];
    for(int i=1;i<=h;i++)
    {
        for(int j=1;j<=w;j++)
        {
            cin>>arr[i][j];
        }
    }
   vector<vector<int>>dp (h+1,vector<int>(w+1,0));
   dp[h][w]=1;
   for(int i=h;i>=1;i--)
   {
       for(int j=w;j>=1;j--)
       {
           if(i==h && j==w)
           continue;
           if(arr[i][j]=='#')
           dp[i][j]=0;
           else
           dp[i][j]=(((i==h) ? 0:dp[i+1][j])+((j==w) ? 0:dp[i][j+1]))%mod;
       }
   }
   cout<<dp[1][1]<<"\n";
return 0;
}