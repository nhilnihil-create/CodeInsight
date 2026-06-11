#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int gcd(int a, int b) {
  if (b == 0) return a;
  return gcd(b, a%b);
}

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n) cin >> a[i];
  int min_hp = a[0];
  for (int i = 1; i < n; ++i) min_hp = gcd(min_hp, a[i]);
  cout << min_hp << endl;
  return 0;
}