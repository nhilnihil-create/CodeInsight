#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(int argc, const char *argv[]) {
  ll n, k;
  cin >> n >> k;
  ll cur = 1;
  for (int i = 0; i < n; i++) {
    if (cur * 2 < cur + k) {
      cur *= 2;
    } else {
      cur += k;
    }
  }

  cout << cur << '\n';
}