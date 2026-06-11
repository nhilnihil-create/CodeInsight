#include <bits/stdc++.h>

using namespace std;
using ll = long long;

//container util
#define SORT(c) sort((c).begin(),(c).end())

//repetition
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)

//print
#define pv(val) cerr << #val << '=' << (val) << endl

const int INF = 1e9;
struct UnionFind{
	vector<int> d;
	UnionFind(int n=0): d(n, -1){}
	int find(int x){
		if(d[x] < 0) return x;
		return d[x] = find(d[x]);
	}
	bool unite(int x, int y){
		x = find(x); y = find(y);
		if(x == y) return false;
		if(d[x] > d[y]) swap(x, y);
		d[x] += d[y];
		d[y] = x;
		return true;
	}
	bool same(int x, int y){ 
		return find(x) == find(y);
	}
	int size(int x){
		return -d[find(x)];
	}
};

int main(void){

	int N, M; cin >> N >> M;
	UnionFind u(N);
	REP(i, M){
		int X, Y, Z; cin >> X >> Y >> Z;
		u.unite(--X, --Y);
	}

	set<int> st;
	REP(i,N){
		st.insert(u.find(i));
	}

	int ans = st.size();
	cout << ans << endl;


	return 0;

}
