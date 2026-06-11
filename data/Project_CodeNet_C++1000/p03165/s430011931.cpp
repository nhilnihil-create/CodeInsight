#include "bits/stdc++.h"
using namespace std;

#define ff first
#define ss second
#define pb push_back
#define int long long

signed main(){


#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
//freopen("output.txt", "w", stdout);
#else
// online submission
#endif

  string a,b;
  cin >> a >> b;
  
  int n=a.size();
  int m=b.size();
  int dp[n+1][m+1];
  
  for(int i=0;i<=n;i++){
    for(int j=0;j<=m;j++){
      if(i==0 || j==0)
        dp[i][j]=0;
      
      else if(a[i-1]==b[j-1]){
        dp[i][j]=1+dp[i-1][j-1];
      }
      else{
        dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
      }
    }
  }
 
  int i=n;
  int j=m;
  string ans;
  while(i>0 && j>0){

    if(a[i-1]==b[j-1]){
      ans+=a[i-1];
      i--; j--;
    }
    
    else if(dp[i][j-1]>=dp[i-1][j]){
      j--;
    }
    else{
      i--;
    }
    
  }
  
  
    reverse(ans.begin(), ans.end()); 
cout<<ans;
  
    return 0;
}


