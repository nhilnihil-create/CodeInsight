#include <bits/stdc++.h>
using namespace std;

int main() {
  string s, t;
  cin >> s >> t;
  int L = -1;
  int sl = s.length();
  int tl = t.length();
  for (int i = 0; i < sl-tl+1; i++) {
    for (int j = 0; j < tl; j++) {
      if (s[i+j] != t[j] && s[i+j] != '?') break;
      else if (j == tl-1) L = i;  
    }
  }
  if (L == -1) {
    cout << "UNRESTORABLE" << endl;
    return 0;
  }
  for (int i = L; i < L+tl; i++) s[i] = t[i-L];

  for (int i = 0; i < sl; i++) {
    if (s[i] == '?') s[i] = 'a';
  }
  cout << s << endl;
}