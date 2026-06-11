#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
const ll M = 1e9 + 7;

int main() {
  int a, b, c;
  cin >> a >> b >> c;
  if (a <= c & c <= b) cout << "Yes" << endl;
  else if (b <= c & c <= a) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}