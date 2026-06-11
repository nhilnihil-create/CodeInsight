#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, A, B;
  cin >> N;
  A = 0;
  B = 0;
  vector<int> X(N);
  for (int i=0; i<N; i++){
  	cin >> X[i];
  }
  sort (X.begin(),X.end());
  reverse (X.begin(),X.end());
  for (int i=0; i<N; i+=2){
    A += X[i];
  }
  for (int i=1; i<N; i+=2){
    B += X[i];
  }
  cout << A-B << endl;
}
