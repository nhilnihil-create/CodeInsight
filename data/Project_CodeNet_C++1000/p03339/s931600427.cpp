#include "bits/stdc++.h"
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  int N;
  cin >> N;
  string S;
  cin >> S;
  vector<int> west(N); //西から数えてi番目までのWの数
  vector<int> east(N); //東から数えてi番目までのEの数
  if(S[0] == 'W'){
    west[0] = 1;
  }
  if(S[N-1] == 'E'){
    east[N-1] = 1;
  }
  rep(i,N-1){
    west[i+1] = west[i] + ((S[i+1] == 'W') ? 1 : 0);
    east[N-i-2] = east[N-i-1] + ((S[N-i-2] == 'E') ? 1 : 0);
  }
  vector<int> diff(N);
  diff[0] = east[1];
  diff[N-1] = west[N-2];
  rep(i,N-2){
    diff[i+1] = east[i+2]+west[i];
  }
  /*
  rep(i,N){
    cout << i << ":" << "W:" << west[i] << ", E:" << east[i] << ", diff:" << diff[i] << endl;
  }
  */
  sort(diff.begin(), diff.end());
  cout << diff[0] << endl;
  return 0;
}