#include <bits/stdc++.h>
#define rep(i, a, n) for(int (i) = (int)(a);(i) < (int)(n);++(i))
#define repe(i, a, n) for(int (i) = (int)(a);(i) <= (int)(n);++(i))
#define repif(i, a, x) for(int (i) = (int)(a);(x);++(i))
#define repr(i, a, n) for(int (i) = ((int)(a)-1);(i) >= (int)(n);--(i))
#define reper(i, a, n) for(int (i) = (int)(a);(i) >= (int)(n);--(i))
#define chmax(a, b) a = max(a, b)
#define chmin(a, b) a = min(a, b)
#define SIZE(x) ((int)(x).size())
#define ALL(x) (x).begin(), (x).end()
#define RNG(x, a, n) &((x)[a]), &((x)[n])
#define ADD(a, b) ((((a)%MOD)+((b)%MOD))%MOD)
#define MUL(a, b) ((((a)%MOD)*((b)%MOD))%MOD)
#define CEIL(x) ((int)ceil(((double)x)))
#define POW(x, y) ((int)pow(x, y))
#define UNIQUE(x) (x).erase(unique(ALL((x))), (x).end())
#define YES cout << "YES" << endl
#define NO cout << "NO" << endl
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl
#define yes cout << "yes" << endl;
#define no cout << "no" << endl;
#define fcout cout << fixed << setprecision(10)
#define pb push_back
#define pf push_front
#define mp make_pair
#define mt make_tuple
#define lb lower_bound
#define ub upper_bound
#define fi first
#define se second
#define EPS (1e-20)
#define INF 214748364700000
#define MOD 1000000007
using llint = long long;
using VI = std::vector<int>;
using PII = std::pair<int, int>;
using SI = std::set<int>;
using MII = std::map<int, int>;
using TIII = std::tuple<int, int, int>;
using VLL = std::vector<llint>;
using MCI = std::map<char, int>;
using namespace std;


struct WUF {
	VI par;
	VI rank;
	VI diffWeight;

	WUF(){}
	void init(int n){
		par.resize(n);
		rank.resize(n);
		diffWeight.resize(n);
		iota(ALL(par), 0);
	}
	int root(int x){
		if(par[x] == x) return x;
		int r = root(par[x]);
		diffWeight[x] += diffWeight[par[x]];
		return par[x] = r;
	}
	int weight(int x){
		root(x);
		return diffWeight[x];
	}
	bool same(int x, int y){
		return root(x) == root(y);
	}
	bool unite(int x, int y, int w){
		w += weight(x), w -= weight(y);
		x = root(x), y = root(y);
		if(x == y) return false;
		if(rank[x] < rank[y]) swap(x, y), w = -w;
		if(rank[x] == rank[y]) rank[x]++;
		par[y] = x;
		diffWeight[y] = w;
		return true;
	}
	int diff(int x, int y){
		return weight(y)-weight(x);
	}
};


int N, M;
WUF uf;


signed main(){
	cin >> N >> M;
	uf.init(N);
	rep(i, 0, M){
		int L, R, D;
		cin >> L >> R >> D, L--,  R--;
		if(uf.same(L, R)){
			if(uf.diff(L, R) != D){
				No;
				return 0;
			}
		}
		else uf.unite(L, R, D);
	}
	
	Yes;

	return 0;
}
