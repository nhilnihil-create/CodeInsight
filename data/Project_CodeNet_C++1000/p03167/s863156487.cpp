#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
int main() 
{
      ll h,w;
      cin>>h>>w;
      char ar[h][w];
      for(int i=0; i<h; i++)
      {
        for(int j=0; j<w; j++)
        {
             cin>>ar[i][j];
        }
      }
      
      ll dp[h][w];
       dp[0][0]=1;
       bool flag=0;
       for(int i=1; i<w; i++)
         {
                if(flag)
                dp[0][i]=0;
                else
                {
                  if(ar[0][i]=='#')
                  { dp[0][i]=0;
                  flag=1;}
                  else
                    dp[0][i]=1;
                }
                
         }
         flag=0;
         for(int i=1; i<h; i++)
         {
                if(flag)
                dp[i][0]=0;
                else
                {
                  if(ar[i][0]=='#')
                  { dp[i][0]=0;
                  flag=1;}
                  else
                    dp[i][0]=1;
                }
                
         }
         for(int i=1; i<h; i++)
         {
           for(int j=1; j<w; j++)
           {   int t1=0,t2=0;
               if(ar[i][j]=='#')
               dp[i][j]=0;
               else
               {
               if(dp[i-1][j]!=0)
                t1=dp[i-1][j];
               if(dp[i][j-1]!=0)
                 t2=dp[i][j-1];
                
                if(t1==INT_MIN && t2==INT_MIN)
                 dp[i][j]=0;
                 else
                 dp[i][j]=((t1%mod)+(t2%mod))%mod;
               }
           }
         }
         
         cout<<(dp[h-1][w-1])%mod<<endl;
         
      
        return 0;
}