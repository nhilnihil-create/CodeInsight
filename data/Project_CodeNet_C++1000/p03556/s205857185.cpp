#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
int main() {
  int64_t N, A, B, C;
  cin >> N;
  A = 1;
  C = 1;
  while(true) {
    B = A;
    A = C * C;
    C++;
    if(A > N) {
      break;
    }
  }
  cout << B << endl;
}