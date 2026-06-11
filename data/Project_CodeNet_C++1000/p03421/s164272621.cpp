#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp> //required
// #include <ext/pb_ds/tree_policy.hpp> //required

// using namespace __gnu_pbds; 
using namespace std;

void debug_out() { cerr << endl; }
template<class T> ostream& prnt(ostream& out, T v) { out << v.size() << '\n'; for(auto e : v) out << e << ' '; return out;}
template<class T> ostream& operator<<(ostream& out, vector <T> v) { return prnt(out, v); }
template<class T> ostream& operator<<(ostream& out, set <T> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, map <T1, T2> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, pair<T1, T2> p) { return out << '(' << p.st << ' ' << p.nd << ')'; }
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) { cerr << " " << H; debug_out(T...);}
// template <typename T> using ordered_set =  tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; // ordered_set <ynt> s; // order_of_key(value)

#define dbg(...) cerr << #__VA_ARGS__ << " ->", debug_out(__VA_ARGS__)
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define st first
#define nd second


const int N = 300100;
int n, k, m, a, b, p[N];

int main() {
	ios_base::sync_with_stdio(false);

	cin >> n >> a >> b;

	for(int i = 1; i <= n; i++) p[i] = i;

	// if(a + b == n + 1) {
	// 	// return 0;
	// 	reverse(p + 1, p + b + 1);
	// 	// reverse	
	// 	for(int i = 1; i <= n; i++) cout << p[i] << ' ';

	// 	return 0;
	// }

		// dbg(1LL * a * b);
		// dbg(a * b);
	if(1LL * a * b < 1LL *n || a + b > n + 1)
		return cout << "-1\n", 0;
	// return 0;
	int rest = n;
	for(int j = 1; j <= n; j += b) {
		rest -= b - 1;
		if(rest >= a)
			reverse(p + j, min(p + j + b, p + n + 1));
		else {
			rest += b - 1;
			int cant = rest - a + 1;
			reverse(p + j, min(p + j + cant, p + n + 1));
			break;
		}
	}

	for(int i = 1; i <= n; i++) cout << p[i] << ' ';
}
