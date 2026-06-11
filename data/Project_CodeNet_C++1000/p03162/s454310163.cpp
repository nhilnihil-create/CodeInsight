#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
  int N;
  cin >> N;
  ll dp[3][100010];
  for(int i=0;i<N;i++){
    int a,b,c;
    cin >>a>>b>>c;
    if(i==0){
      dp[0][i]=a;
      dp[1][i]=b;
      dp[2][i]=c;
    }
    else{
      dp[0][i]=max(dp[1][i-1],dp[2][i-1])+a;
      dp[1][i]=max(dp[0][i-1],dp[2][i-1])+b;
      dp[2][i]=max(dp[0][i-1],dp[1][i-1])+c;
    }
  }
  int ans=max(dp[0][N-1],max(dp[1][N-1],dp[2][N-1]));
  cout << ans <<endl;
}
            
  