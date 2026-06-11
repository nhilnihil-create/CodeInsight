#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<int, int> P;
ll Mod = 1000000007;
int main() {
  string S;
  cin >> S;
  bool alpha[26];
  for (int i = 0; i < 26; i++) {
    alpha[i] = false;
  }
  if (S == "zyxwvutsrqponmlkjihgfedcba") {
    cout << -1 << endl;
    return 0;
  }
  if (S.size() != 26) {
    for (int i = 0; i < S.size(); i++) {
      alpha[S[i] - 'a'] = true;
    }
    for (int i = 0; i < 26; i++) {
      if (!alpha[i]) {
        S += 'a' + i;
        break;
      }
    }
    cout << S << endl;
  } else {
    int end;
    for (int i = 25; i >= 1; i--) {
      if (S[i-1] < S[i]) {
        end = i;
        break;
      }
    }
    S = S.substr(0,end);
    for (int i = 0; i < S.size() - 1; i++) {
      alpha[S[i] - 'a'] = true;
    }
    for (int i = 0; i < 26; i++) {
      if (S[S.size() - 1] < 'a' + i && !alpha[i]) {
        S[S.size() - 1] = 'a' + i;
        break;
      }
    }
    cout << S << endl;
  }
  return 0;
}