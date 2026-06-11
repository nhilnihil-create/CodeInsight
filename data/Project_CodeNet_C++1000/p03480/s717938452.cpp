#include <bits/stdc++.h>
using namespace std;
int main() {
  string S;
  cin >> S;
  int zero = S.length(), one = S.length();
  for (int i = 0; i < S.length(); i++) {
    if (S[i] == '1') {
      one = min(one,max(i,(int)S.length()-i-1));
    }
    if (S[i] == '0') {
      zero = min(zero,max(i,(int)S.length()-i-1));
    }
  }
  cout << max(one,zero);
}