#define _DEBUG 1
#define _GLIBCXX_DEBUG

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#ifdef _DEBUG
#define dump(x) cerr << #x << "=" << x << endl
#define dump2(x, y) cerr << #x << "=" << x << "," << #y << "=" << y << endl
#define dump3(x, y, z)                                                         \
  cerr << #x << "=" << x << "," << #y << "=" << y << "," << #z << "=" << z     \
       << endl
#define check(s) cerr << s << endl
#else
#define dump(x)
#define dump2(x, y)
#define dump3(x, y, z)
#define check(s)
#endif

#define rep(i, n) for (ll i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define unique(v) v.erase(unique(v.begin(), v.end()), v.end());

void yes() { cout << "YES" << endl; }
void no() { cout << "NO" << endl; }
void yesOrNo(bool flg) {
  if (flg)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
}

void solve(string s1, string s2) {
  bool result =
      s1.at(0) == s2.at(2) && s1.at(1) == s2.at(1) && s1.at(2) == s2.at(0);
  yesOrNo(result);
}

int main() {
  string s1, s2;
  cin >> s1;
  cin >> s2;
  solve(s1, s2);
  return 0;
}
