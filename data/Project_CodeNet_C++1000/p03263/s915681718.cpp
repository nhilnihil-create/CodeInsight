#include "bits/stdc++.h"
using namespace std;

// Inserted snippets: io, root
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
template<typename H> bool chmin(H& v1, const H v2) { if (v1 > v2) { v1 = v2; return true; } return false; }
template<typename H> bool chmax(H& v1, const H v2) { if (v1 < v2) { v1 = v2; return true; } return false; }
template<typename H> void read(H& head) { cin >> head; }
template<typename H, typename ...T> void read(H& head, T& ...tail) { cin >> head; read(tail...); }
template<typename H> void write(H head) { cout << head << '\n'; }
template<typename H, typename ...T> void write(H head, T ...tail) { cout << head << " "; write(tail...); }
template<typename ...T> void die(T ...tok) { write(tok...); exit(0); }
// End snippets

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

  int h, w; read(h, w);
  vector<vector<int>> v(h, vector<int>(w, 0));
  rep(i, 0, h) rep(j, 0, w) read(v[i][j]);
  
  vector<pair<int, int>> pth;
  vector<pair<pii, pii>> ans;

  rep(i, 0, h)
    rep(j, 0, w)
      pth.push_back({ i, i % 2 == 0 ? j : w - 1 - j });

  vector<pii> temp;
  for (auto p : pth) {
    int i, j; tie(i, j) = p;
    if (v[i][j] & 1) {
      if (temp.empty()) temp.push_back(p);
      else {
        temp.push_back(p);
        rep(i, 0, sz(temp) - 1)
          ans.push_back({ temp[i], temp[i + 1] });
        temp.clear();
      }
    } else {
      if (temp.size()) temp.push_back(p);
    }
  }

  write(sz(ans));
  for (auto p : ans) {
    write(p.first.first + 1, p.first.second + 1, p.second.first + 1, p.second.second + 1);
  }
}
