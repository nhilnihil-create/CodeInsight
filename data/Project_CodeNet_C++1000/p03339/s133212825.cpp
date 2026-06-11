#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;

  string S;
  cin >> S;
  vector<int> west(N+1, 0);
  vector<int> east(N+1, 0);
  for(int i=0; i<N; i++){
    if (S[i] == 'W'){
      west[i+1] = west[i] + 1;
      east[i+1] = east[i];
    }else{
      west[i+1] = west[i];
      east[i+1] = east[i] + 1;
    }
  }

  int minVal = 10000000;
  for(int i=0; i<N; i++){
    minVal = min(minVal, (west[i]-west[0] + east[N] - east[i+1]));
  }
  cout << minVal;
  return 0;
}