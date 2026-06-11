#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  int h[100005];
  int dp[100005] = {};
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>h[i];
  }
  for(int i=1;i<n;i++){
    if(i==1){
      dp[i] = abs(h[i]-h[i-1]);
    }
    else{
      dp[i] = min(abs(h[i]-h[i-1])+dp[i-1],abs(h[i]-h[i-2])+dp[i-2]);           
    }
  }
  cout<<dp[n-1]<<'\n';
}
		  
  

