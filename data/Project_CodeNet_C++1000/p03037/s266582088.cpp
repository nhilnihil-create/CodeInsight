#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  int L, R;
  cin >> L >> R;
  for(int i = 0; i < M - 1; i++) {
    int l, r;
    cin >> l >> r;
    if(r < L || R < l) {
      cout << 0 << endl;
      return 0;
    }
    if(r < R) {
      R = r;
    }
    if(l > L) {
      L = l;
    }
  }
  cout << R - L + 1 << endl;
}