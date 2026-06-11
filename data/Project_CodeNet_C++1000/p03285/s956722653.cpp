#include <bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for (int i=(a); i<(b); i++)

int main() {
  int N;
  cin >> N;
  bool ans = false;
  FOR(i, 0, 30) {
    FOR(j, 0, 20) {
      if ((4*i + 7*j) == N) {
        ans = true;
      }
    }
  }
  if (ans) cout << "Yes" << endl;
  else cout << "No" << endl;
return 0;
}