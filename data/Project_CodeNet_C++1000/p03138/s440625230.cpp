#include<bits/stdc++.h>
using namespace std;

int main(){
  int64_t N, K;
  cin >> N >> K;
  vector<string> vec(N);
  int X = 60;
  for(int i=0; i<N; i++){
    int64_t x;
    cin >> x;
    stringstream ss;
    ss << bitset<60>(x);
    string S = ss.str();
    vec.at(i) = S;
  }
  stringstream ss;
  ss << bitset<60>(K);
  string k = ss.str();
  
  vector<int64_t> one(X,0);
  for(int i=0; i<N; i++){
    for(int j=0; j<X; j++){
      if(vec.at(i).at(j) == '1'){
        one.at(j)++;
      }
    }
  }
  vector<int64_t> pow2(X,1);
  for(int i=X-1; i>0; i--){
    pow2.at(i-1) = pow2.at(i)*2;
  }
  
  int64_t dp[X+1][2];
  for(int i=0; i<X+1; i++){
    for(int j=0; j<2; j++){
      dp[i][j] = 0;
    }
  }
  
  bool start = false;
  
  for(int i=0; i<X; i++){
    if(!start){
      if(k.at(i) == '1'){
        start = true;
        dp[i+1][0] = pow2.at(i)*(N-one.at(i));
        dp[i+1][1] = pow2.at(i)*one.at(i);
      }
      continue;
    }
    int64_t x = k.at(i) - '0';
    for(int j=0; j<2; j++){
      for(int k=0; k<2; k++){
        int64_t ni = i+1;
        int64_t nj = j;
        int64_t nx = pow2.at(i)*one.at(i); 
        if(j == 0 && k < x){
          nj++;
        }
        if(nj == 0 && x < k){
          continue;
        }
        if(k == 1){
          nx = pow2.at(i)*(N-one.at(i));
        }
        dp[ni][nj] = max(dp[ni][nj], dp[i][j] + nx);
      }
    }
  }
  
  /*for(int i=0; i<X+1; i++){
    for(int j=0; j<2; j++){
      cout << dp[i][j] << " ";
    }
    cout << endl;
  }*/
  
  int64_t ans = max(dp[X][0], dp[X][1]);
  
  for(int i=0; i<X; i++){
    if(k.at(i) == '1'){
      break;
    }
    ans += one.at(i)*pow2.at(i);
  }
  cout << ans << endl;
}