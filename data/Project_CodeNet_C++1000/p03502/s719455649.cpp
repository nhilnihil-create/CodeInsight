#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,W;
  cin >> N;
  int S = N;
  for(; N>0; N /= 10){
    W += N%10;
  }
  if(S%W == 0){
    cout << "Yes" << endl;
  return 0;
  }
  cout << "No" << endl;
}
