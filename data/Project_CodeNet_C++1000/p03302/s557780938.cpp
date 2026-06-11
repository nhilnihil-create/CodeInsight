#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e16;
const ll mod = 1000000007;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  ll a, b;
  cin >> a >> b;
  if (a+b == 15) cout << '+' << endl;
  else if (a*b == 15) cout << '*' << endl;
  else cout << 'x' << endl;
}