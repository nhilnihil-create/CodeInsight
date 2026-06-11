#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define _GLIBCXX_DEBUG

int main() {
  int N;
  cin >> N;
  vector<int64_t> L(N+1);
  if (N == 1) {
    cout << 1 << endl;
  }
  else {
    L[0] = 2;
    L[1] = 1;
    rep(i, N-1) {
      L[i+2] = L[i+1] + L[i];
    }
    cout << L[N] << endl;
  }
}
