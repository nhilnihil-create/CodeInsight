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

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	int n, m; read(n, m);
	map<int, map<int, int>> hist;

	rep(i, 1, m + 1) {
		int p, y; read(p, y);
		hist[p][y] = i;
	}
	
	vector<string> ans(m + 1);
	
	for (auto p : hist) {
		int ind = 1;
		for (auto p2 : p.second) {
			char buf[13];
			sprintf(buf, "%06d%06d", p.first, ind++);
			ans[p2.second] = string(buf);
		}
	}

	rep(i, 1, m + 1) write(ans[i]);
}
