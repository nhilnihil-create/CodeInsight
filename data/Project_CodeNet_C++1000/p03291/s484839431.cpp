// #include<iostream>
// #include<vector>
// #include<algorithm>
// #include<map>
// #include<cstring>
// #include<math.h>
// #include<bitset>
// #include<queue>
// #include<set>
// #include<iomanip>
// #include<math.h>
// #include<assert.h>
// #include<string>
// #include<cstdlib>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr ll INF = 1LL << 40;
const double INFD = 1e100;
const ll mod = 1000000007;
const double PI = 3.1415926535897932384626433832795028841971;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
// ----------------------------------------------------------------------------
ll dp[100010][4];
int main(){
  string S;
  cin >> S;
  int N;
  N = S.size();
  for(int i=0; i<10010; i++){
    for(int j=0; j<4; j++){
      dp[i][j] = 0;
    }
  }
  for(int i=N; i>=0; i--){
    for(int j=3; j>=0; j--){
      if(i == N){
        if(j == 3){
          dp[i][j] = 1;
        }else{
          dp[i][j] =0;
        }
      }else{
        if(S[i] == '?'){
          dp[i][j] = dp[i+1][j] * 3LL;
        }else{
          dp[i][j] = dp[i+1][j];
        }
        if(j < 3 && S[i] == '?' || S[i] == "ABC"[j]){
          dp[i][j] += dp[i+1][j+1];
        }
        dp[i][j] %= mod;
      }
    }
  }
  cout << dp[0][0] << endl;
  return 0;
}
