#include <bits/stdc++.h>
using namespace std;

int N, X;

int main(){

  cin >> N >> X;

  int m[N];
  int mMin = 1e9;
  int counter = N;

  for(int i = 0; i < N; ++i){
    cin >> m[i];
    X -= m[i];
    if(m[i] < mMin) mMin = m[i];
  }

  counter += X/mMin;
  cout << counter ;

  return 0; 
}