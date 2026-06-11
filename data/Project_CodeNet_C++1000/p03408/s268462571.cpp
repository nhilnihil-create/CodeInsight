#include <bits/stdc++.h>
using namespace std;

vector<string> v_input(int L) {
  vector<string> v(L);
  for (int i = 0; i < L; i++) {
    cin >> v.at(i);
  }
  return v;
}

int main() {
  int N, M;
  cin >> N;
  vector<string> S = v_input(N);
  cin >> M;
  vector<string> T = v_input(M);
  
  int Max = 0;
  for (int i = 0; i < N; i++) {
    int C = 0;
    for (int k = 0; k <= i; k++) {
      if (S.at(k) == S.at(i)) {
        C++;
      }
    }
    if (C > 1) {continue;}
    
    int count = 0;
    for (int j = 0; j < N; j++) {
      if (S.at(i) == S.at(j)) {
        count++;
      } 
    }
    
    for (int j = 0; j < M; j++) {
      if (S.at(i) == T.at(j)) {
        count--;
      } 
    }   
    Max = max(Max, count);
  }

  cout << Max << endl;
  
}
