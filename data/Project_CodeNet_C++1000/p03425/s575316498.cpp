#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define printVec(v) printf("{"); for (const auto& i : v) { std::cout << i << ", "; } printf("}\n");
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
using namespace std;
using P = pair<int,int>;
using ll = long long;
const ll INF = 1LL<<60;
const double PI = 3.1415926535897932;
const int MOD = 1e9 + 7;

//cin.tie(0);ios::sync_with_stdio(false);
int main() {
  int n;
  cin >> n;
  map<char, ll> mci;
  rep (i, n) {
    string s;
    cin >> s;
    if (s[0] != 'M' && s[0] != 'A' && s[0] != 'R' && s[0] != 'C' && s[0] != 'H') {
      continue;
    }
    mci[s[0]]++;
  }

  if (mci.size() < 3) {
    cout << 0 << endl;
    return 0;
  } else if (mci.size() == 3) {
    ll res = 1;
    for (auto v : mci) {
      res *= v.second;
    }

    cout << res << endl;
    return 0;
  }


  vector<char> skip1;
  for (auto v : mci) skip1.push_back(v.first);

  vector<string> skip2;
  for (int i = 0; i < skip1.size() - 1; i++) {
    for (int j = i + 1; j < skip1.size(); j++) {
      string s = "";
      s += skip1[i];
      s += skip1[j];
      skip2.push_back(s);
    }
  }

  ll ans = 0;
  if (mci.size() == 4) {
    for (auto sk : skip1) {
      ll tmp = 1;
      for (auto v : mci) {
        if (v.first == sk) continue;
        tmp *= v.second;
      }
      ans += tmp;
    }
  } else if (mci.size() == 5) {
    for (auto sk : skip2) {
      ll tmp = 1;
      for (auto v : mci) {
        if (v.first == sk[0] || v.first == sk[1]) continue;
        tmp *= v.second;
      }
      ans += tmp;
    }
  }

  cout << ans << endl;
  return 0;
}
