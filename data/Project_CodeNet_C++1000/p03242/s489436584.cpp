#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  string S;
  cin >> S;
  for (int i = 0; i < 3; i++) {
    if (S[i] == '9') cout << 1;
    else cout << 9;
  }
  cout << endl;
}
