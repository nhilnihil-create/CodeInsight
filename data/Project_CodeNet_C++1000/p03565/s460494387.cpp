#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define pb push_back
#define all(v) (v).begin(), (v).end()
#define fi first
#define se second
#define sz(x) ((int)(x).size())
using ll = long long;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define MOD 1000000007
const ll INF = 1e18;
template <class T>
void show(vector<T> v) {
  for (int i = 0; i < v.size(); i++) {
    cerr << v[i] << " ";
  }
  cerr << endl;
}
template <class T>
inline bool chmax(T& a, T b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
inline bool chmin(T& a, T b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}

int main() {
  string a, b;
  cin >> a >> b;
  for (int i = a.length() - b.length(); i >= 0; --i) {
    for (int q = 0; q < b.length(); ++q) {
      if (a[i + q] != b[q] && a[i + q] != '?') goto failed;
    }
    for (int q = 0; q < b.length(); ++q) {
      a[i + q] = b[q];
    }
    for (int q = 0; q < a.length(); ++q) {
      if (a[q] == '?') a[q] = 'a';
    }
    cout << a << endl;
    return 0;
  failed:;
  }
  cout << "UNRESTORABLE" << endl;
  return 0;
}