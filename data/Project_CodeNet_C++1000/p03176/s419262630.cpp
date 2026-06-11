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

// max segtree
struct segtree {
	ll seg[800005];
	void update(int nid, int l, int r, int pos, ll v) {
		if (l == pos && pos == r) {
			seg[nid] = v;
			return;
		}

		int m = l + r >> 1;
		if (pos <= m) update(nid * 2, l, m, pos, v);
		else update(nid * 2 + 1, m + 1, r, pos, v);

		seg[nid] = max(seg[nid * 2], seg[nid * 2 + 1]);
	}
	ll query(int nid, int l, int r, int ql, int qr) {
		if (ql == l && qr == r) return seg[nid];

		int m = l + r >> 1;
		if (qr <= m) return query(nid * 2, l, m, ql, qr);
		else if (ql > m) return query(nid * 2 + 1, m + 1, r, ql, qr);
		else return max(
				query(nid * 2, l, m, ql, m),
				query(nid * 2 + 1, m + 1, r, m + 1, qr));
	}
} seg;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	int n; read(n);
	
	vector<pair<int, pair<int, ll>>> v(n);
	rep(i, 0, n) v[i].second.first = i + 1;
	rep(i, 0, n) read(v[i].first);
	rep(i, 0, n) read(v[i].second.second);

	sort(all(v));

	rep(i, 0, n) {
		int h = v[i].first, pos = v[i].second.first; ll val = v[i].second.second;
		seg.update(1, 0, n, pos, seg.query(1, 0, n, 0, pos - 1) + val);
	}

	die(seg.query(1, 0, n, 0, n));
}
