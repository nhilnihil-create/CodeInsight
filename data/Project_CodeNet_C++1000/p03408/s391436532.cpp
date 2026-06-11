#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<string> S(N);
  for (int i=0; i<N; i++) {
    cin >> S.at(i);
  }
  
  int M;
  cin >> M;
  vector<string> T(M);
  for (int i=0; i<M; i++) {
    cin >> T.at(i);
  }
  
  int score=0;
  
  for (int i=0; i<N; i++) {
    int a=0;
    for (int j=0; j<N; j++) {
      if (S.at(i) == S.at(j)) {
        a++;
      }
    }
    
    for (int j=0; j<M; j++) {
      if (S.at(i) == T.at(j)) {
        a--;
      }
    }
    
    if (a > score) {
      score = a;
    }
  }
  
  cout << score << endl;
}