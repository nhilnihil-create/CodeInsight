#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;

  while (true) {
    string s = to_string(N);
    char c = s[0];
    bool ok = true;
    for (int i = 1; i < 3; i++) {
      if(c != s[i]) ok = false;
    }
    if (ok) break;
    N++;
  }
  cout << N << endl;
  return 0;
}