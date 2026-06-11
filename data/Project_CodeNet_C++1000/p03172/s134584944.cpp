#include<bits/stdc++.h>
using namespace std;
int main(){
  
  int N,K;
  long long int mod = (long long int )(pow(10,9)+7);
  cin >> N >> K;
  vector<int> inp;
  int temp;
  long long int dp[N][K+1];
  for(int i=0;i<N;i++){
    
    cin >> temp;
    inp.push_back(temp);
    
  }
  sort(inp.begin(),inp.end());
  for(int i=0;i<N;i++){
    for(int j=0;j<=K;j++){
      if(j==0){
       	dp[i][j]=1;
        continue;
      }
      if(i==0){
       	 
        if(j<=inp[i]) dp[i][j]=1;
        else dp[i][j]=0;
        continue;
      }
     else{
       if(j-inp[i]-1>=0) dp[i][j] = (mod+(dp[i][j-1]+dp[i-1][j])%mod-dp[i-1][j-inp[i]-1])%mod;
       else dp[i][j] = (dp[i][j-1]+dp[i-1][j])%mod;
       
     }
    }
  }
  cout << dp[N-1][K];
  return 0;
  
  
}