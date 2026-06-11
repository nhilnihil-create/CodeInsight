#include <iostream>

using namespace std;
using ll = long long;

int main() {
  string S;
  string T;
  cin >> S >> T;
  int s = S.length(), t = T.length();
  if (s >= t) {
    for (int i = s-t; i >= 0; --i) {
      bool flag = true;
      for (int j = 0; j != t; ++j) {
        if (S[i+j] != '?' && S[i+j] != T[j]) {
          flag = false;
          break;
        }
      }
      if (flag) {
        for (int j = 0; j != s; ++j) {
          if (S[j] == '?') {
            if (j >= i && j < i + t) S[j] = T[j-i];
            else S[j] = 'a'; 
          }
        }
        cout << S << endl;
        return 0;
      }
    }
  }
  cout << "UNRESTORABLE" << endl;
}
