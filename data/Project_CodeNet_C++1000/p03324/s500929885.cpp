#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
int main() {
  int D, N;
  cin >> D >> N;
  if(D == 0) {
    if(N == 100) {
      cout << 101 << endl;
    }
    else {
      cout << N << endl;
    }
  }
  else if(D == 1) {
    if(N == 100) {
      cout << 10100 << endl;
    }
    else {
      cout << 100 * N << endl;
    }
  }
  else {
    if(N == 100) {
      cout << 1010000 << endl;
    }
    else {
      cout << 10000 * N << endl;
    }
  }
}