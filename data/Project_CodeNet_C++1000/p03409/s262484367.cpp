#include <bits/stdc++.h>


#define rep2(x,fr,to) for(int (x)=(fr);(x)<(to);(x)++)
#define rep(x,to) for(int (x)=0;(x)<(to);(x)++)
#define repr(x,fr,to) for(int (x)=(fr);(x)>=(to);(x)--)
#define all(c) (c).begin(),(c).end()
#define sz(v) (int)(v).size()

using namespace std;
typedef long long ll; typedef vector<int> VI; typedef pair<int,int> pii;
const int MD = (int)1e9 + 7; typedef vector<ll> VL;
void dbg(){ cerr << "\n"; }  template <class T, class ...T2>
void dbg(const T& fst, const T2&...rst){ cerr << fst << ": "; dbg(rst...); }
template <class T, class T2> void amax(T& a,T2 b){ if(a < b) a = b;}

class bipartite_matching {
public:
	int n;
	vector<vector<int>> g;
	vector<int> match;
	bipartite_matching(int n_) : n(n_), g(n_), match(n_), used(n_) {}
	void add_edge(int u, int v) {
		g[u].push_back(v);
		g[v].push_back(u);
	}
	int maximum_matching(void) {
		int res = 0;
		fill(begin(match), end(match), -1);
		for (int v = 0; v < n; ++v) {
			if (match[v] == -1) {
				fill(begin(used), end(used), false);
				if (dfs(v)) res++;
			}
		}
		return res;
	}

private:
	vector<int> used;
	bool dfs(int v) {
		used[v] = true;
		for (int u : g[v]) {
			int w = match[u];
			if (w == -1 || (!used[w] && dfs(w))) {
				match[v] = u;
				match[u] = v;
				return true;
			}
		}
		return false;
	}
};

int main()
{
	cin.tie(0); ios_base::sync_with_stdio(false);
	int n;
	cin >>n;
	vector<VI> ab(n, VI(2));
	bipartite_matching bm(2*n);
	rep(i, n) cin >>ab[i][0] >>ab[i][1];
	rep(j, n){
		int c, d; cin >>c >>d;
		rep(i, n) if( c > ab[i][0] && d > ab[i][1]) bm.add_edge(i, j+n);
	}
	int ans = bm.maximum_matching();
	
	cout << ans <<"\n";
	return 0;
}
