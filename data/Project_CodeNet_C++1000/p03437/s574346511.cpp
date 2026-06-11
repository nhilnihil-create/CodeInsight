#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int64_t n, m;
  cin >> n >> m;
  if (n%m != 0) {
    cout << n << endl;
  } else {
    cout << -1 << endl;
  }
}