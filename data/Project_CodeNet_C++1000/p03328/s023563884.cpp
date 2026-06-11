#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
const ll INF = 1LL << 60;

int main(void) {
  int a, b;
  cin >> a >> b;
  cout << (b - a) * (b - a + 1) / 2 - b << '\n';
  return 0;
}