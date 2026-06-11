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

int sat[100005], satps[100005], sieve[100005];

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
  
  fill(sieve, sieve + 100005, 1);
  sieve[0] = sieve[1] = 0;
  rep(i, 2, 100005)
    for (ll j = 1ll * i * i; j < 100005; j += i)
      sieve[j] = 0;
  rep(i, 0, 100005)
    sat[i] = (i % 2 == 1 && sieve[i] && sieve[(i + 1) / 2]);
  rep(i, 1, 100005)
    satps[i] = satps[i - 1] + sat[i];
  int q; read(q);
  rep(i, 0, q) {
    int l, r; read(l, r);
    write(satps[r] - satps[l - 1]);
  }
}
