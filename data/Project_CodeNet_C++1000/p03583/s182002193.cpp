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

// 1/i + 1/j + 1/k = 4/n
// n(ij+jk+ki) = 4ijk

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	constexpr double eps=1e-12;
	double n; read(n);
	for (ll i=1;i<=3500;i++) for (ll j=1;j<=3500;j++) {	
		double rem = 4/n - 1./i - 1./j;
		if (rem <= 0) continue;
		ll k = ll(round(1/rem));
		if (k>3500) continue;
		if (n*(i*j+j*k+k*i)==4*i*j*k)
			die(i,j,k);
	}
}
