#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M, A, X = 0;
  cin >> N;
  vector<string> blue(N);
  //blue代入
  for (int i = 0; i < N; i++){
    cin >> blue.at(i);
  }
  //red代入
  cin >> M;
  vector<string> red(M);
  for (int i = 0; i < M; i++){
    cin >> red.at(i);
  }
  for (int i = 0; i < N; i++){
    A = 1;
    for (int j = i + 1; j < N; j++){
      if (blue.at(i) == blue.at(j)){
        A += 1;
      }
    }
    for (int k = 0; k < M; k++){
      if (blue.at(i) == red.at(k)){
        if (A == 0)
          continue;
        A -= 1;
      }
    }
    if (X < A)
      X = A;
  }
  cout << X << endl;
}