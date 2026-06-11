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

  string s, t;
  read(s);
  for (char c : s) if (c != 'x') t += c;
  if (t != string(t.rbegin(), t.rend())) die(-1);
  if (t.empty()) die(0);

  //write(t);

  s = '$' + s + '$';
  int n = sz(s);
  int pl, pr;
  for (int i = 0, j = 0; i < n; i++) {
    bool sp = s[i] != 'x' && s[i] != '$';
    if (sp) j++;
    //if (sp) write("sp", i, s[i], j, sz(t) / 2, sz(t) / 2 + 1);
    if (sp && sz(t) % 2 == 1 && j == sz(t) / 2 + 1)
      pl = pr = i;
    if (sp && sz(t) % 2 == 0 && j == sz(t) / 2)
      pl = i;
    if (sp && sz(t) % 2 == 0 && j == sz(t) / 2 + 1)
      pr = i;
  }
  
  int ans = 0;
  rep(i, 0, sz(t) / 2 + 1) {
    int cl = 0, cr = 0;
    //write(pl, pr, s[pl], s[pr]);
    pl--, pr++;
    while (s[pl] == 'x') --pl, ++cl;
    while (s[pr] == 'x') ++pr, ++cr;
    ans += abs(cr - cl);
    //write(':', abs(cr - cl));
  }
  write(ans);
}
