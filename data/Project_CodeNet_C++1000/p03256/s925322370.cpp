#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_p(x) cerr<<#x": "<<x.first<<","<<x.second<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define st first
#define nd second

using namespace std;

const int N = 900100;
int n, k, m, a, b, use[N], now[N];
string s;
vector <int> v[N], c[N];

template<class T>
ostream& operator<<(ostream& out, vector<T> v) {
	out << v.size() << '\n';
	for(auto e : v) out << e << ' ';
	return out;
}

template<class T1, class T2>
ostream& operator<<(ostream& out, pair<T1, T2> p) {
	return out << '(' << p.st << ' ' << p.nd << ')';  
}


bool dfs(int node, int usg, int t) {
	now[node] = 1;
	use[node] = usg;
	for(auto i : v[node]) {
		if(use[i] == 0) {
			if(dfs(i, usg, node))
				return true;
		}
		else if(i != t && use[i] == usg && now[i])
			return true;
	}
	now[node] = 0;
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	cin >> s;
	s = " " + s;
	for(int i = 1; i <= m; i++) {
		cin >> a >> b;
		if(s[a] == 'A' && s[b] == 'A') {
			v[a].push_back(n + b);
			if(a != b)
				v[b].push_back(n + a);
		}
		if(s[a] == 'B' && s[b] == 'B') {
			v[2 * n + a].push_back(3 * n + b);
			if(a != b)
				v[2 * n + b].push_back(3 * n + a);
		}
		if(s[a] == 'A' && s[b] == 'B') {
			v[n + a].push_back(2 * n + b);
			v[3 * n + b].push_back(a);
		}
		if(s[a] == 'B' && s[b] == 'A') {
			v[n + b].push_back(2 * n + a);
			v[3 * n + a].push_back(b);
		}
	}

	dbg(v[3]);
	dbg(v[7]);
	dbg(v[8]);
	dbg(v[10]);
	dbg(v[13]);

	for(int i = 1; i <= n; i++) {
		dbg_ok;
		if(dfs(i, i, -1)) {
			cout << "Yes\n";
			return 0;
		}
	}
	cout << "No\n";
}	