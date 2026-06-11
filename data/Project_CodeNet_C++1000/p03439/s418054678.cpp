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
  int n; read(n);
  int l = 0, r = n - 1;
  string pl, pr;
  cout << l << endl; read(pl); if (pl[0] == 'V') return 0;
  cout << r << endl; read(pr); if (pr[0] == 'V') return 0;
  while (true) {
    int m = l + r >> 1;
    if (m == l || m == r) break;
    string res;
    cout << m << endl; read(res); if (res[0] == 'V') return 0;
    if ((m - l) % 2 == 1 && res[0] == pl[0]) r = m, pr = res;
    else if ((m - l) % 2 == 0 && res[0] != pl[0]) r = m, pr = res;
    else if ((r - m) % 2 == 1 && res[0] == pr[0]) l = m, pl = res;
    else if ((r - m) % 2 == 0 && res[0] != pr[0]) l = m, pl = res;
  }
  rep(i, l + 1, r) {
    cout << i << endl; string s;
    read(s); if (s[0] == 'V') return 0;
  }
}
