#include<bits/stdc++.h>
using namespace std;
string to_string(const string& s) {
	return '"' + s + '"';
}
string to_string(const bool b) {
	return (b ? "true" : "false");
}
string to_string(const char* s) {
	return to_string((string)s);
}
string to_string(const char c) {
	string s = "'";
	s += c;
	s += "'";
	return s;
}
template<class T, class U>
string to_string(const pair<T, U>& p) {
	string s = "(";
	s += to_string(p.first);
	s += ", ";
	s += to_string(p.second);
	s += ")";
	return s;
}
template<class T>
string to_string(const T& a) {
	bool first = true;
	string s = "{";
	for (const auto& x : a) {
		if(!first){
			s += ", ";
		}
		first = false;
		s += to_string(x);
	}
	s += "}";
	return s;
}
void debug_out() {cerr << '\n';}
template<class Head, class... Tail>
void debug_out(Head head, Tail... tail) {
	cerr << ' ' << to_string(head);
	debug_out(tail...);
}
#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "] = ", debug_out(__VA_ARGS__)
#else
#define debug(...)
#endif
using ll = long long;
using ld = long double;
const int mod1 = 1e9 + 7;
const int mod2 = 1e9 + 9;
const int inf = 1e9 + 100;
const ll inf64 = 7e18l;
const ll b1 = 1123456122;
const ll b2 = 1122541422;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout << fixed << setprecision(20);
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	int p = 0;
	ll answer = 0;
	int now = 0;
	int cnt = 0;
	for (int i = 0; i < n; ++i) {
		if (i > 0) {
			--cnt;
			now ^= a[i - 1];
		}
		while (p < n && (a[p] & now) == 0) {
			now ^= a[p];
			++p;
			++cnt;
		}	
		answer += cnt;
	}
	
	cout << answer << '\n';
}
