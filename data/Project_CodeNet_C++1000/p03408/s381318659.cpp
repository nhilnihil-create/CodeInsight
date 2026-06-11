#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  
  vector<string> vec0(N);
  for(int i = 0; i < N; i++) {
    cin >> vec0.at(i);
  }
  
  int M;
  cin >> M;
  vector<string> vec1(M);
  for(int i = 0; i < M; i++) {
    cin >> vec1.at(i);
  }
  
  int X = 0;
  
  for(int i = 0; i < N; i++) {
    int count = 0;
    for(int j = 0; j < N; j++) {
      if(vec0.at(i) == vec0.at(j)) {
        count++;
      }
    }
    for(int j = 0; j < M; j++) {
      if(vec0.at(i) == vec1.at(j)) {
        count--;
      }
    }
    if(X < count) {
      X = count;
    }
  }
  cout << X << endl; 
}
