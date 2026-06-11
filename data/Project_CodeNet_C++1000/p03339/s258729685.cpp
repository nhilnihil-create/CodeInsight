#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  
  vector<char> S(N);
  for(int i = 0; i < N; i++){
    cin >> S.at(i);
  }
  
  vector<int> LW(N),RE(N);
  
  for(int i = 1; i < N; i++){
    if(S[i-1] == 'W'){
      LW[i] = LW[i-1] + 1;
    }
    else{
      LW[i] = LW[i-1];
    }
  }
  
  for(int i = N-2; i >= 0; i--){
    if(S[i+1] == 'E'){
      RE[i] = RE[i+1] + 1;
    }
    else{
      RE[i] = RE[i+1];
    }
  }
  
  int sum;
  int m = 300000;
  for(int i = 0; i < N; i++){
    sum = LW[i] + RE[i];
    if(sum < m){
      m = sum;
    }
  }
  cout << m << endl;
}