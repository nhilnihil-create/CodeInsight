#include<bits/stdc++.h>
using namespace std;
#define boost ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

long long int mod=1e9+7,maximum=-1;
char ar[1001][1001];

 long long int getmax(long long int n,long long int m)
{
  
    long long int i,j;
    long long int dp[n+1][m+1];

    
   
    for(i=0;i<n+1;i++)
    dp[i][0]=0;
    for(j=0;j<m+1;j++)
    dp[0][j]=0;
    dp[0][1]=1;
    
     for(i=1;i<n+1;i++)
     {
         for(j=1;j<m+1;j++)
         {
             if(ar[i-1][j-1]=='#')
             dp[i][j]=0;
             else
             {
                 dp[i][j]=(dp[i-1][j]+dp[i][j-1])%mod;
             }
             
         }}
     
         
   
 
  
    return dp[n][m]%mod;

    

}
int main()
{
     long long int n,m;
    
    
   
        cin>>n>>m;

        
         long long int i,j;
        for(  i=0;i<n;i++)
        for(j=0;j<m;j++)
   
        cin>>ar[i][j];
        cout<<getmax(n,m)<<"\n";
    
}
