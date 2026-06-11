#include <bits/stdc++.h>
using namespace std;

int main() {

  int X, N, K;
  X = 1;
  cin >> N >> K;
  for(int i = 0;i < N;i++){
  if((X * 2) > (X + K)){
  X = X + K;
  }else{
  X = X * 2;
  }
  }
  cout << X << endl;

}