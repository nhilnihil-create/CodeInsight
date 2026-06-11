#include <bits/stdc++.h>
using namespace std;
int main(){
  int N;
  cin >> N;
  vector<int> a, b;
  if (N % 2 == 0){
    for (int i = 1; i <= N; i++){
      for (int j = i + 1; j <= N; j++){
        if (i + j != N + 1){
          a.push_back(i);
          b.push_back(j);
        }
      }
    }
  } else {
    for (int i = 1; i <= N; i++){
      for (int j = i + 1; j <= N; j++){
        if (i + j != N){
          a.push_back(i);
          b.push_back(j);
        }
      }
    }
  }
  int M = a.size();
  cout << M << endl;
  for (int i = 0; i < M; i++){
    cout << a[i] << ' ' << b[i] << endl;
  }
}