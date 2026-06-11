/* BABA JAGAAAAAA  */  

#include<bits/stdc++.h>
#define pb push_back
#define un unordered_map
#define us unordered_set
#define ll long long
#define fast ios:: sync_with_stdio(false);cin.tie(NULL)
#define l long 
using namespace std;
const int  mod= 1e9+7;
const int inf=1e9+3;

 int main()
 {
     fast;  
        string s,t;
         cin>>s>>t;
        int m,n;
         m=s.size();
         n= t.size();
         int  dp[m+1][n+1];
         for(int i=0; i<=m; i++)
         {
              for(int j=0; j<=n; j++)
              {
                   if(i==0 || j==0)
                   dp[i][j]=0;
                   else if(s[i-1]==t[j-1])
                   dp[i][j]=1+dp[i-1][j-1];
                   else
                   {
                       dp[i][j]= max(dp[i-1][j], dp[i][j-1]);
                   }
              }
         }
         
         string res;
         int lx=m;
         int ly=n;
         while(lx>0 && ly>0)
         {
             if(s[lx-1]==t[ly-1]){
                 res+=s[lx-1];
                 lx--,ly--;
             }
             
             else if(dp[lx-1][ly]>dp[lx][ly-1])
              lx--;
              else
              ly--;
         }
          reverse(res.begin(), res.end());
          cout<<res;
           
    
       return 0;
     
 }
  