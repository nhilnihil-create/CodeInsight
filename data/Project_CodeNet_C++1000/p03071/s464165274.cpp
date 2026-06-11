#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e16;
const ll mod = 1000000007;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  ll a, b;
  cin >> a >> b;
  if (a > b) cout << 2*a-1 << endl;
  else if (a == b) cout << 2*a << endl;
  else cout << 2*b-1 << endl;
}