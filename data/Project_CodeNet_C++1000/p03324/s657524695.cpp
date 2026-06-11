#include <bits/stdc++.h>
using namespace std;

int main() {
  int D,N;
  cin >> D >> N;
  int s = 1;
  for(int i = 0;i < D;i++){
  s *= 100;
  }
  if(N < 100){
  cout << s*N;
  }
  else{
  cout << s*(N+1);
  }
}