#include<bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  vector<int> vec(100);
  vec[0]=1;
  int a;
  int cnt=0;
  for(int i=1;;i++){
    a=pow(6,i);
    if(a>N){
      break;
    }
    cnt++;
    vec[cnt]=a;
  }
  for(int i=1;;i++){
    a=pow(9,i);
    if(a>N){
      break;
    }
    cnt++;
    vec[cnt]=a;
  }
  sort(vec.begin(),vec.end(),greater<int>());
  vector<int> dp(100010,200000);
  dp[0]=0;
  for(int i=0;i<=N;i++){
    for(int j=cnt;j>=0;j--){
      if(i<vec[j]){
        break;
      }
      dp[i]=min(dp[i-vec[j]]+1,dp[i]);
    }
  }
  cout << dp[N] <<endl;
}