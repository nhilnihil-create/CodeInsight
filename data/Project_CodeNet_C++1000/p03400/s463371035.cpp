#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N, D, X;
  cin >> N >> D >> X;
  vector<int> A(N);
  for(int i = 0; i < N; i++){
    cin >> A.at(i);
  }
  vector<int> C(N);
  for(int i = 0; i < N; i++){
    for(int j = 0; j < 100; j++){
      if(j*A.at(i) + 1 <= D)C.at(i)++;
    }
  }
  int sum = 0;
  for(int i = 0; i < N; i++){
    sum += C.at(i);
  }
  cout << sum + X << endl;
}
  