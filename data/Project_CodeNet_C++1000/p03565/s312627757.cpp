#include <bits/stdc++.h>
using namespace std;

string chmin (string& S, string T) {
  if (S > T) S = T;
  
  return S;
}

int main() {
  string S, T;
  
  cin >> S >> T;
  int M = S.size(), N = T.size();
  
  int Tstart = -1;
  string ans = "zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz";
  for (int i = 0; i + N - 1< M; i++) {
    bool cond = true;
    for (int j = 0; j < N; j++) {
      if (S[i+j] != T[j] && S[i+j] != '?') {
        cond = false;
        break;
      }
    }
    
    if (cond) {
      Tstart = i;
      string s;
      int k = 0;
      for (int j = 0; j < M; j++) {
        if (j >= i && j < i + N) {
          s += T[k];
          k++;
        } else if (S[j] == '?'){
          s += 'a';
        } else {
          s += S[j]; 
        }
      }
      ans = chmin(ans, s);
    }
    
  }
  if (Tstart == -1) {
    cout << "UNRESTORABLE" << endl;
  } else {
    cout << ans << endl;
  }
}