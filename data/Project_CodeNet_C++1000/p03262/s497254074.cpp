#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, s, n) for (int i = (s); i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int gcd(int a, int b) {
  if (a > b) {
    ll tmp = b;
    b = a;
    a = tmp;
  }
  int r = b % a;
  while (r != 0) {
    b = a;
    a = r;
    r = b % a;
  }
  return a;
}

int main() {
  int n, x;
  cin >> n >> x;
  vector<int> v;
  v.push_back(x);
  rep(i, n) {
    int num;
    cin >> num;
    v.push_back(num);
  }
  sort(v.begin(), v.end());
  if (n == 1) {
    cout << v[1] - v[0] << endl;
  } else {
    int l = gcd(v[1] - v[0], v[2] - v[1]);
    rep(i, n - 1) l = gcd(l, v[i + 1] - v[i]);
    cout << l << endl;
  }
  return 0;
}
