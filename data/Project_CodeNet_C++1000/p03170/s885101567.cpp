#define LOCAL

#undef _GLIBCXX_DEBUG

#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(false);cin.tie(0)
#define all(x) x.begin(), x.end()
#define ff first
#define ss second
#define MOD 1000000007LL
#define LLINF 100000000000000005LL
#define INF (int)1e9+1

// Copied from Gennady-Korotkevich's template

template <typename A, typename B>
string to_string(pair<A, B> p);

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p);

template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p);

string to_string(const string& s) {
	return '"' + s + '"';
}

string to_string(const char* s) {
	return to_string((string)s);
}

string to_string(bool b) {
	return (b ? "true" : "false");
}

string to_string(vector<bool> v) {
	bool first = true;
	string res = "{";
	for (int i = 0; i < static_cast<int>(v.size()); i++) {
		if (!first) {
			res += ", ";
		}
		first = false;
		res += to_string(v[i]);
	}
	res += "}\n";
	return res;
}

template <size_t N>
string to_string(bitset<N> v) {
	string res = "";
	for (size_t i = 0; i < N; i++) {
		res += static_cast<char>('0' + v[i]);
	}
	return res;
}

template <typename A>
string to_string(A v) {
	bool first = true;
	string res = "{";
	for (const auto& x : v) {
		if (!first) {
			res += ", ";
		}
		first = false;
		res += to_string(x);
	}
	res += "}\n";
	return res;
}

template <typename A, typename B>
string to_string(pair<A, B> p) {
	return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p) {
	return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")";
}

template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p) {
	return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";
}

template <typename A, typename B, typename C, typename D, typename E>
string to_string(tuple<A, B, C, D, E> p) {
	return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + "," + to_string(get<4>(p)) + ")";
}

void debug_out() {
	cerr << endl;
}

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
	cerr << " " << to_string(H);
	debug_out(T...);
}

#ifdef LOCAL
#define debug(...) cerr << "\n[" << #__VA_ARGS__ << "]:\n", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

// End of Gennady-Korotkevich's template 

using llong = long long;
using PII = pair<int, int>;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

pii operator+(pii a, pii b)
{
	return { a.ff + b.ff,a.ss + b.ss };
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	vector<int> dp(k + 1);
	for (int i = 0; i < a[0]; i++) dp[i] = -1;
	for (int i = 0; i <= k; i++) {
		bool suc = false;
		for (int j = 0; j < n; j++) {
			if (i - a[j] < 0) break;
			if (dp[i - a[j]] < 0) suc = true;
		}
		if (suc) dp[i] = 1;
		else dp[i] = -1;
	}
	//debug(dp);
	if (dp[k] == 1) cout << "First";
	else cout << "Second";

	return 0;
}