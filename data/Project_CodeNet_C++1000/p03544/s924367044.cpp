#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n;
  cin >> n;
  vector<ll> l(n+1);
  l[0] = 2;
  l[1] = 1;
  for (int i = 2; i <= n; ++i) l[i] = l[i-1] + l[i-2];
  cout << l[n] << endl;
  return 0;
}