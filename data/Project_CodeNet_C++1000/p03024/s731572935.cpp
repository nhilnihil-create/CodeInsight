#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  int N;
  cin >> S;
  N = S.size();
  int x = 0;
  for (int i=0; i<N; i++) {
    if (S[i] == 'x') {
      x++;
    }
  }
  if (x >= 8) {
    cout << "NO" << endl;
  }
  else {
    cout << "YES" << endl;
  }
}