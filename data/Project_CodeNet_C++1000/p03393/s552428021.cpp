#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  string S;
  cin >> S;
  int s = S.size();
  if (s != 26) {
    vector<bool> alphabet(26, false);
    for (int i = 0; i < s; i++) {
      alphabet[(int)(S[i]-97)] = true;
    }
    int unuse;
    for (int i = 0; i < 26; i++) {
      if (!alphabet[i]) {
        unuse = i;
        break;
      }
    }
    char plus = (char)(97+unuse);
    S.push_back(plus);
    cout << S << endl;
  }
  else {
    if (S == "zyxwvutsrqponmlkjihgfedcba") {
      cout << -1 << endl;
      return 0;
    }
    string T = S;
    next_permutation(S.begin(), S.end());
    for (int i = 0; i < s; i++) {
      cout << S[i];
      if (S[i] != T[i]) break;
    }
    cout << endl;
  }
}
