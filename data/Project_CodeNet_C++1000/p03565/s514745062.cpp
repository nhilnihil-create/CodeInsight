#include <bits/stdc++.h>
#define IOS                                                                    \
  ios::sync_with_stdio(0);                                                     \
  cin.tie(0);                                                                  \
  cout.tie(0)
#define pb push_back
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using ll = long long;
using vi = vector<int>;
using pii = pair<ll, ll>;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;
ll bpow(ll b, ll p, ll m = 1000000007LL) {
  ll rt = 1;
  for (; p; p >>= 1, b = b * b % m)
    if (p & 1)
      rt = rt * b % m;
  return rt;
}
bool check(string a, string b) {
  for (int i = 0; i < a.length(); i++) {
    if (a[i] != '?' && a[i] != b[i])
      return 0;
  }
  return 1;
}
int main() {
  IOS;
  string s, t;
  cin >> s >> t;
  vector<string> v;
  for (int i = 0; i < s.length() - t.length() + 1; i++) {
    if (check(s.substr(i, t.length()), t)) {
      // cout << s.substr(i, t.length()) << ' ' << t << endl;
      string tmp = s;
      for (int j = i; j < i + t.length(); j++)
        tmp[j] = t[j - i];
      // cout << tmp << endl;
      for (int j = 0; j < s.length(); j++)
        if (tmp[j] == '?')
          tmp[j] = 'a';
      v.pb(tmp);
    }
  }
  sort(all(v));
  if (v.empty()) {
    cout << "UNRESTORABLE" << endl;
  } else {
    cout << v[0] << endl;
  }
}
