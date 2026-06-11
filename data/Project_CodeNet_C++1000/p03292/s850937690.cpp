#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;

int main() {
  int A1, A2, A3;
  cin >> A1 >> A2 >> A3;

  cout << max({A1, A2, A3}) - min({A1, A2, A3}) << endl;
  return 0;
}