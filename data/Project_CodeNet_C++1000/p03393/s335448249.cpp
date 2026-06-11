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

	string s; read(s);
	if (sz(s) == 26) {
		if (s == "zyxwvutsrqponmlkjihgfedcba")
			write(-1);
		else {
			string t;
			while (s[sz(s) - 2] > s[sz(s) - 1]) {
				s.pop_back();
			}
			s.pop_back();
			char d = s.back(); s.pop_back();
			//write(s, d);
			set<char> sc(all(s));
			for (char c = d + 1; c <= 'z'; c++)
				if (sc.find(c) == sc.end()) {
					s += c;
					write(s);
					return 0;
				}
		}
	} else {
		set<char> sc(all(s));
		for (char c = 'a'; c <= 'z'; c++)
			if (sc.find(c) == sc.end()) {
				s += c;
				write(s);
				return 0;
			}
	}
}
