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
template<typename H, typename ...T> void write(H head, T ...tail) { cout << head << " "; print(tail...); }

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	ll n, m; read(n, m);
	string s, t; read(s, t);

	ll len = n * m / __gcd(n, m);
	
	map<ll, char> mp;
	rep(i, 0, n) mp[i * len / n] = s[i];
	rep(i, 0, m) {
		if (mp.find(i * len / m) != mp.end() && mp[i * len / m] != t[i]) {
			write(-1);
			return 0;
		}
	}

	write(len);
}
