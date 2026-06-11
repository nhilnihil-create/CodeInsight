#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;
template<class T> void assign(V<T>& v, int n, const T& a = T()) { v.assign(n, a); }
template<class T, class... U> void assign(V<T>& v, int n, const U&... u) { v.resize(n); for (auto&& i : v) assign(i, u...); }

int main() {
  cin.tie(NULL); ios::sync_with_stdio(false);
  lint n, k; cin >> n >> k;
  if (k & 1) cout << (n / k) * (n / k) * (n / k) << '\n';
  else {
    lint m = (n + k / 2) / k;
    cout << (n / k) * (n / k) * (n / k) + m * m * m << '\n';
  }
}