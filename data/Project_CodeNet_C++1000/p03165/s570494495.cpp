#include<bits/stdc++.h>
using namespace std;
int main(){
  string a,b;
  cin>>a>>b;
  vector<vector<int>> dp(a.length()+1,vector<int>(b.length()+1,0));
  for(int i=1;i<=a.length();i++)
  {
  	for(int j=1;j<=b.length();j++){
    	if(a[i-1]==b[j-1]){
        	dp[i][j]=dp[i-1][j-1]+1;
        }
      	else{
        	dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
  }
  int i=a.length();int j=b.length();
  string ans;
  while(i>0&&j>0){
  	if(a[i-1]==b[j-1]){
    	ans+=a[i-1];
      	i--;j--;
    }
    else if(dp[i-1][j]>dp[i][j-1]){
    	i--;
    }
    else j--;
  }
  reverse(ans.begin(),ans.end());
  cout<<ans<<endl;
  return 0;
}