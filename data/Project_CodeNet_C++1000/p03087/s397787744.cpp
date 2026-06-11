#include <bits/stdc++.h>
using namespace std;

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

int f[100005], ps[100005];
int n, q;
string s;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	read(n, q, s);
	rep(i, 0, n - 1)
		if (s.substr(i, 2) == "AC")
			f[i] = 1;
	rep(i, 0, n - 1)
		ps[i] = (i ? ps[i - 1] : 0) + f[i];
	rep(i, 0, q) {
		int l, r; read(l, r);
		l--; r--;
		if (l == r) write(0);
		else {
			write(ps[r - 1] - (l ? ps[l - 1] : 0));
		}
	}
}
