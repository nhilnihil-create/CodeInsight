#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  string S;
  cin >> S;
  bool can = true;
  int length = S.size();
  int cnt_C = 0;
  if (S[0] != 'A') can = false;
  if ((int)S[1] - 97 < 0) can = false;
  if ((int)S[length-1] - 97 < 0) can = false;
  if (can) {
    for (int i = 2; i < length-1; i++) {
      if (S[i] == 'C') cnt_C++;
      else {
        if ((int)S[i] - 97 < 0) {
          can = false;
          break;
        }
      }
    }  
  }
  if (cnt_C != 1) can = false;
  
  if (can) cout << "AC";
  else cout << "WA";
}
