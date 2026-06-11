#include <bits/stdc++.h>
#define rep(i, a, n) for (int i = a; i < n; i++)
#define repr(i, a, n) for (int i = n - 1; i >= a; i--)
using namespace std;
using ll = long long;
using P = pair<int, int>;
template <typename T> void chmin(T &a, T b) { a = min(a, b); }
template <typename T> void chmax(T &a, T b) { a = max(a, b); }

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;
  vector<string> ab, a, b, c;
  rep(i, 0, n) {
    string s;
    cin >> s;
    if (s[0] == 'B' && s[s.size() - 1] == 'A')
      ab.push_back(s);
    else if (s[0] == 'B')
      b.push_back(s);
    else if (s[s.size() - 1] == 'A')
      a.push_back(s);
    else
      c.push_back(s);
  }

  int ai = 0, bi = 0, abi = 0;
  int as = a.size(), bs = b.size(), abis = ab.size();
  string ts = "";

  if (ai < as){
    ts += a[ai];
    ai++;
  }
  rep(i, 0, (int)ab.size()) ts += ab[i];
  if (bi < bs){
    ts += b[bi];
    bi++;
  }

  while (ai < as || bi < bs) {
    if (ai < as) {
      ts += a[ai];
      ai++;
    }

    if (bi < bs) {
      ts += b[bi];
      bi++;
    }
  }

  rep(i, 0, (int)c.size()) ts += c[i];

  int ans = 0;
  string find_word = "AB";
  string::size_type pos = ts.find(find_word);
  while (pos != string::npos) {
    ans++;
    pos = ts.find(find_word, pos + find_word.size());
  }

  cout << ans << endl;
}
