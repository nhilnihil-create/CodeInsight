#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int main() {
  int a, b, x;
  cin >> a >> b >> x;
  if(x < a || (a + b) < x) cout << "NO" << endl;
  else cout << "YES" << endl;
}
