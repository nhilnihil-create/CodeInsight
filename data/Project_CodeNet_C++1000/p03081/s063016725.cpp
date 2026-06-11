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

int n, m;
string s;
vector<pair<char, int>> v;

int f(int x) {
	rep(i, 0, m) {
		if (s[x] == v[i].first)
			x += v[i].second;
	}
	return x;
}

template<class T, class U>
T lower_bound_on(T first, T last, const U& value, const function<U(T)>& fn) {
	T it, step, count = last - first;
	while (count > 0) {
		it = first + (step = count / 2);
		if (fn(it) < value)
			first = ++it, count -= step + 1;
		else
			count = step;
	}
	return first;
}

template<class T, class U>
T upper_bound_on(T first, T last, const U& value, const function<U(T)>& fn) {
	T it, step, count = last - first;
	while (count > 0) {
		it = first + (step = count / 2);
		if (!(value < fn(it)))
			first = ++it, count -= step + 1;
		else	
			count = step;
	}
	return first;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	cin >> skipws;

	read(n, m, s);
	s = ' ' + s + ' ';
	v = vector<pair<char, int>>(m);
	rep(i, 0, m) {
		char c;
		read(v[i].first, c);
		v[i].second = c == 'L' ? -1 : 1;
	}

	int left = upper_bound_on<int, int>(0, n + 2, 1, f);
	int right = lower_bound_on<int, int>(0, n + 2, n + 1, f);

	write(right - left);
}
