#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {

  ll n, m;
  cin >> n >> m;
  cout << ((n - m) * 100 + m * 1900) * (2<<(m-1));
  return 0;
}
