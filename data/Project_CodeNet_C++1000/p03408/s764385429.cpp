#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M, X = 0;
  int max;
  
  cin >> N;
  vector<string> s(N);
   for(int i = 0; i < N ; i++) {
     cin >> s.at(i);
  }
  
  cin >> M;
  vector<string> t(M);
   for(int i = 0; i < M ; i++) {
     cin >> t.at(i);
  }
  
  max = 0;
  for(int i = 0; i < N ; i++) {
    for(int j = M-1; j >= 0 ; j--) {
      if(s.at(i) == t.at(j) && t.at(j) != "") {
        X--;
        t.at(j) = "";
      }
    }
    for(int k = N-1; k >= i; k--) {
      if(s.at(i) == s.at(k) && s.at(k) != "") {
        X++;
        s.at(k) = "";
      }
    }
    if(max < X) {
      max = X;
    }
    X = 0;
  }
  cout << max << endl;
}
