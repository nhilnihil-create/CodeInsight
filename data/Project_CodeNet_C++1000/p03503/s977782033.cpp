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

int f[105][10], p[105][11];

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

  int n; read(n);
  rep(i, 0, n) rep(j, 0, 10) read(f[i][j]);
  rep(i, 0, n) rep(j, 0, 11) read(p[i][j]);

  ll ans = -0x3f3f3f3f3f3f3f3fll;
  rep(b, 1, 1 << 10) {
    ll val = 0;
    rep(i, 0, n) {
      int cnt = 0;
      rep(j, 0, 10) if (b & (1 << j) && f[i][j]) cnt++;
      val += p[i][cnt];
    }
    chmax(ans, val);
  }
  write(ans);
}
