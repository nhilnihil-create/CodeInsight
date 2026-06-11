#include<bits/stdc++.h>
using namespace std;

string big(string T, string U){
  string ans = T;
  if(T.size() < U.size()){
    ans = U;
  }
  else if(T.size() == U.size()){
    for(int i=0; i<T.size(); i++){
      if(T.at(i) > U.at(i)){
        break;
      }
      else if(T.at(i) < U.at(i)){
        ans = U;
        break;
      }
    }
  }
  return ans;
}

int main(){
  int N, M;
  cin >> N >> M;
  vector<int> vec(M);
  vector<int> match = {0,2,5,5,4,5,6,3,7,6};
  for(int i=0; i<M; i++){
    cin >> vec.at(i);
  }
  string dp[N+1];
  for(int i=0; i<N+1; i++){
    dp[i] = "";
  }
  for(int i=1; i<N+1; i++){
    for(int j=0; j<M; j++){
      int c = match[vec.at(j)]; //使うマッチ棒の数
      if(i - c < 0){
        continue;
      }
      if(i - c != 0 && dp[i-c] == ""){
        continue;
      }
      else{
        char x = '0' + vec.at(j);
        string S = dp[i-c] + x;
        string T = x + dp[i-c];
        dp[i] = big(dp[i],S);
        dp[i] = big(dp[i],T);
      }
    }
  }
  /*for(int i=0; i<N; i++){
    cout << i << " " << dp[i] << endl;
  }*/
  cout << dp[N] << endl;
}