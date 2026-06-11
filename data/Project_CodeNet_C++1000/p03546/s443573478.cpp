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

int h, w;
int c[10][10];
int a[200][200];

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	read(h, w);
	rep(i, 0, 10) rep(j, 0, 10) read(c[i][j]);
	rep(i, 0, h) rep(j, 0, w) read(a[i][j]);

	rep(k, 0, 10) rep(i, 0, 10) rep(j, 0, 10)
		chmin(c[i][j], c[i][k] + c[k][j]);
	
	ll ans = 0;
	rep(i, 0, h) rep(j, 0, w) if (a[i][j] != -1) 
		ans += c[a[i][j]][1];

	die(ans);
}
