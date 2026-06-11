#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int N;
  cin >> N;
  bool res = false;
  for (int a = 0; a <= N/4; a++) {
    for (int b = 0; b <= N/7; b++) {
      int total = 4*a + 7*b;
      if (total == N) res = true;
    }
  }

  if (res) cout << "Yes" << endl;
  else cout << "No" << endl;

  return 0;
}