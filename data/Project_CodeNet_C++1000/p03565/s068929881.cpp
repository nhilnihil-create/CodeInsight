#include<iostream>
#include<string>
using namespace std;

int main() {
  string S, T; cin >> S >> T;
  int M = S.size(), N = T.size();
  if (N > M) cout << "UNRESTORABLE" << endl;
  else {
    string min_s(M, '~');
    for (int i = 0; i <= M - N; i++) {
      bool sat = true;
      for (int j = 0; j < N; j++) {
        if (S[i+j] != '?' && S[i+j] != T[j]) sat = false;
      }
      if (sat) {
        string s(S);
        for (int i = 0; i < M; i++) {
          if (s[i] == '?') s[i] = 'a';
        }
        for (int j = 0; j < N; j++) s[i+j] = T[j];
        min_s = min(min_s, s);
      }
    }
    if (min_s[0] == '~') cout << "UNRESTORABLE" << endl;
    else cout << min_s << endl;
  }
}