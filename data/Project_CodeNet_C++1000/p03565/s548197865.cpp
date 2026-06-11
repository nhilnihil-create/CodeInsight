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
  read(s, t);
  if (sz(t) > sz(s))
    die("UNRESTORABLE");

  set<string> strings;
  rep(i, 0, sz(s) - sz(t) + 1) {
    string res = s;
    for (int j = i, k = 0; k < sz(t); j++, k++)
      if (res[j] == t[k] || res[j] == '?')
        res[j] = t[k];
      else
        goto bad;
    for (char &c : res) if (c == '?') c = 'a';
    strings.insert(res);    
bad: void(0);
  }

  if (strings.size())
    die(*strings.begin());
  else
    die("UNRESTORABLE");
}
