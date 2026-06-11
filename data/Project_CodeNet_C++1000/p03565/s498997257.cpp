#include <bits/stdc++.h>
using namespace std;

int main () {
  string S,T;
  cin >> S >> T;
  int N = S.size();
  int M = T.size();
  int L = -1;
  for (int i = 0; i < N-M+1; i++) {
    for (int j = 0; j < M; j++) {
      if (S.at(i+j) != T.at(j) && S.at(i+j) != '?'){
        break;
      }
      else if (j == M-1){
        L = i;
      }
    }
  }
  
  if (L == -1){
    cout << "UNRESTORABLE" << endl;
    return 0;
  }

  for (int i = L; i < L+M; i++) {
    S.at(i) = T.at(i-L);
  }
  
  for (int i = 0; i < N; i++) {
    if (S.at(i) == '?'){
      S.at(i) = 'a';
    }
  }
  cout << S << endl;
}

