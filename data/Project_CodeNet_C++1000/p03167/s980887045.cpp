/*THERE'S ALWAYS SOMETHING , NOT THAT YOU WOULD UNDERSTAND . YOU ARE LIKE MY SISTER ,
 EVERYTHING ALWAYS CAME EASY TO HER .
 SHE'S A FIRE BENDING PRODIGY AND EVERY ONE ADORE HER . MY FATHER SAYS
 SHE WAS BORN LUCKY ,HE SAYS I WAS LUCKY TO BE BORN . I DON'T NEED LUCK THOUGH .
 I DON'T WANT IT . I'VE ALWAYS HAD TO STRUGGLE AND FIGHT
 AND THAT'S MADE ME STRONG . IT MADE ME WHO I AM .*/
#include<bits/stdc++.h>
using namespace std;
char grid[1024][1024];  //dp[i] = length of longest path starting at i;
int solve(int n,int m)
{
   long long int dp[n+1][m+1];
   dp[n][m]=1;
   for(int i=n;i>=1;i--)
   {
       for(int j=m;j>=1;j--)
       {
           if(i==n&&j==m)continue;
           if(grid[i][j]=='#')
            dp[i][j]=0;
          else dp[i][j]=(((i==n)?0:dp[i+1][j])+((j==m?0:dp[i][j+1])))%1000000007;
       }
   }
   return dp[1][1];
}
main()
{
    int n,m;
    cin>>n>>m;
  for(int i=1;i<=n;i++)
  {
      for(int j=1;j<=m;j++)
      {
          cin>>grid[i][j];
      }
  }
  cout<<solve(n,m)%1000000007;

}






















































































































/* WHATEVER DOESNT KILL ME ONLY MAKES ME STRONGER .*/
