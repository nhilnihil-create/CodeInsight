#include <bits/stdc++.h>
using namespace std;
int64_t lucas(int N){
  if (N == 0){
    return 2;
  }
  if (N == 1){
    return 1;
  }
  if (N == 29){
    return 1149851;
  }
  if (N == 30){
    return 1860498;
  }
  if (N == 59){
    return 2139295485799;
  }
  if (N == 60){
    return 3461452808002;
  }
  return lucas (N - 1) + lucas (N - 2);
}


int main() {
  int N;
  cin >> N;
  cout << lucas(N) << endl;
}

