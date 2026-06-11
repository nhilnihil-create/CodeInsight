#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;

int main() {
  int a, b, c;
  cin >> a >> b >> c;
  cout << b + min(a + b + 1, c) << endl;
  return 0;
}