#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, A, S;
  string op;
  cin >> N >> A;
  S = N / 1000;
  N = N - S * 1000;
  if (N >= 500){
  N = N - 500;
  }
  
  if (N <= A){
  cout << "Yes" << endl;
  }
  else{
  cout << "No" << endl;
  }
  
}