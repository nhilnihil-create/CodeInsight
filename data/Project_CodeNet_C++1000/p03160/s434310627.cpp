#include <bits/stdc++.h>
using namespace std;

int main()
{ 
 int n;
 cin>>n;
 vector<int> ar(n);
 for(int i=0;i<n;++i)
 {
   cin>>ar[i];
 }
 vector<int> dp(n+1,0);
 dp[1]=0;
 dp[2]=abs(ar[1]-ar[0]);
 for(int i=3;i<=n;++i)
 {
   dp[i]=min(dp[i-1]+abs(ar[i-1]-ar[i-2]),dp[i-2]+abs(ar[i-1]-ar[i-3]));
 }
 cout<<dp[n]<<'\n';
}  

  
 
        
        
  


  
