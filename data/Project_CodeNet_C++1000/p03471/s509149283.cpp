#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i <= (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
int main() {
  int N, S;
  cin >> N >> S;
  int A, B, C;
  A = B = C = -1;
  rep(i, N) {
    rep(j, N - i) {
      if(i * 10000 + j * 5000 + (N - i - j) * 1000 == S) {
        A = i;
        B = j;
        C = N - i - j;
      }
    }
  }
  cout << A << " " << B << " " << C << endl;
}