#include <bits/stdc++.h>
#define st first
#define nd second

using namespace std;

void debug_out() { cerr << endl; }
template<class T> ostream& prnt(ostream& out, T v) { out << v.size() << '\n'; for(auto e : v) out << e << ' '; return out;}
template<class T> ostream& operator<<(ostream& out, vector <T> v) { return prnt(out, v); }
template<class T> ostream& operator<<(ostream& out, set <T> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, map <T1, T2> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, pair<T1, T2> p) { return out << '(' << p.st << ' ' << p.nd << ')'; }
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) { cerr << " " << H; debug_out(T...);}

#define dbg(...) cerr << #__VA_ARGS__ << " ->", debug_out(__VA_ARGS__)
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

const int N = 200100;
int n, h, ans, w, x[N], y[N], black[N];
vector <pair<int, int> > v;
int main() {
	ios_base::sync_with_stdio(false);

	cin >> h >> w >> n;
	
	ans = h;
	for(int i = 1; i <= n; i++) {
		cin >> x[i] >> y[i];
		if(x[i] < y[i]) continue;
		v.push_back({x[i] + y[i], i});
	}

	sort(v.begin(), v.end());

	int min_dif = 0;
	for(auto i : v) {
		if(x[i.nd] - y[i.nd] < min_dif) continue;
		if(x[i.nd] - y[i.nd] == min_dif)
			min_dif = x[i.nd] - y[i.nd] + 1;
		else
			ans = min(ans, x[i.nd] - 1);
	}

	cout << ans << '\n';
}	

	