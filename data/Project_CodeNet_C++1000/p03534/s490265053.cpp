#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V  = vector<T>;
template<class T = int> using VV = V< V<T> >;
template<class T, class H> void rsz(V<T> &v, H h) { v.resize(h); }
template<class T, class H, class... R> void rsz(V<T> &v, H h, R... r) { v.resize(h); for (auto&& i : v) rsz(i, r...); }

int main() {
  cin.tie(NULL); ios::sync_with_stdio(false);
  string s; cin >> s;
  V<> n(3); for (char c : s) n[c - 'a']++;
  sort(n.begin(), n.end());
  cout << (n[2] - n[0] <= 1 ? "YES" : "NO") << '\n';
}