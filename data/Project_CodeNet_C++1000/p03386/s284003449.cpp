#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i <= (int)(n); i++)
int main() {
  int A, B, N;
  cin >> A >> B >> N;
  if(B - A + 1 <= 2 * N) {
    rep2(i, A, B) {
      cout << i << endl;
    }
  }
  else {
    rep2(i, A, A+N-1) {
      cout << i << endl;
    }
    rep2(i, B-N+1, B) {
      cout << i << endl;
    }
  }
}