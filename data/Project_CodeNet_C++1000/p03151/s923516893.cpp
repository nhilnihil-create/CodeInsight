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

	int n; read(n);
	vector<int> a(n), b(n);
	rep(i, 0, n) read(a[i]);
	rep(i, 0, n) read(b[i]);

	{
		bool g = true;
		rep(i, 0, n) if (a[i] < b[i]) g = false;
		if (g) die(0);
	}

	{
		ll sa = 0, sb = 0;
		rep(i, 0, n) sa += a[i], sb += b[i];
		if (sa < sb)
			die(-1);
	}

	ll s = 0; int c = 0;
	priority_queue<ll> pq;
	rep(i, 0, n) 
		if (a[i] < b[i])
			s += b[i] - a[i], c++;
		else if (a[i] > b[i])
			pq.push(a[i] - b[i]);
	while (s > 0)
		s -= pq.top(), pq.pop(), c++;
	write(c);
}
