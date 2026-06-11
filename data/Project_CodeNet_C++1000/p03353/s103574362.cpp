#include <bits/stdc++.h>
using namespace std;
template <class T, class U>
ostream &operator<<(ostream &os, const pair<T, U> &p) {
  os << "(" << p.first << "," << p.second << ")";
  return os;
}
#ifdef __LOCAL
#define debug(x) cerr << __LINE__ << ": " << #x << " = " << x << endl
#define debugArray(x, n)                           \
  cerr << __LINE__ << ": " << #x << " = {";        \
  for (long long hoge = 0; (hoge) < (n); ++(hoge)) \
    cerr << ((hoge) ? "," : "") << x[hoge];        \
  cerr << "}" << endl
#else
#define debug(x) (void(0))
#define debugArray(x, n) (void(0))
#endif

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  string s;
  cin >> s;
  int K;
  cin >> K;
  vector<string> mi(K, string(5010, 'z'));
  auto insert = [&](string s) {
    for (int i = 0; i < K; i++) {
      if (mi[i] == s) return;
      if (mi[i] > s) swap(mi[i], s);
    }
  };
  int N = s.length();
  for (int i = 0; i < N; i++)
    for (int j = i + 1; j <= N; j++) insert(s.substr(i, j - i));
  cout << mi.back() << '\n';
  return 0;
}
