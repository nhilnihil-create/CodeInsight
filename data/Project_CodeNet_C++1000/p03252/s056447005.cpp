#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
int main() {
  string S, T;
  cin >> S >> T;
  vector<char> StoT(26, '.'), TtoS(26, '.');
  bool can = true;
  for (int i = 0; i < S.size(); i++) {
    if (StoT[S[i]-'a'] == '.') StoT[S[i]-'a'] = T[i];
    else {
      if (StoT[S[i]-'a'] != T[i]) {
        can = false;
        break;
      }
    }
    if (TtoS[T[i]-'a'] == '.') TtoS[T[i]-'a'] = S[i];
    else {
      if (TtoS[T[i]-'a'] != S[i]) {
        can = false;
        break;
      }
    }
  }
  if (can) cout << "Yes" << endl;
  else cout << "No" << endl;
}
