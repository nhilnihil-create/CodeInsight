#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)
#define all(c) c.begin(),c.end()
#define pb push_back
#define fs first
#define sc second
#define chmin(x,y) x=min(x,y)
#define chmax(x,y) x=max(x,y)
using namespace std;
template<class S,class T> ostream& operator<<(ostream& o,const pair<S,T> &p){
	return o<<"("<<p.fs<<","<<p.sc<<")";
}
template<class T> ostream& operator<<(ostream& o,const vector<T> &vc){
	o<<"{";
	for(const T& v:vc) o<<v<<",";
	o<<"}";
	return o;
}
using ll = long long;
template<class T> using V = vector<T>;
template<class T> using VV = vector<vector<T>>;
constexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n-1); }

#ifdef LOCAL
#define show(x) cerr << "LINE" << __LINE__ << " : " << #x << " = " << (x) << endl
#else
#define show(x) true
#endif

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);		//DON'T USE scanf/printf/puts !!
	cout << fixed << setprecision(20);
	
	int N;
	cin >> N;
	VV<int> G(N);
	rep(i,N-1){
		int x,y;
		cin >> x >> y;
		x--,y--;
		G[x].pb(y);
		G[y].pb(x);
	}
	V<int> d(N);
	function<void(int,int)> dfs = [&](int v,int p){
		if(p != -1) d[v] = d[p] + 1;
		else d[v] = 0;
		for(int u:G[v]) if(u!=p) dfs(u,v);
	};
	dfs(0,-1);
	int far = 0;
	rep(i,N) if(d[far] < d[i]) far = i;
	dfs(far,-1);
	int dia = 0;
	rep(i,N) chmax(dia,d[i]);
	cout << (dia%3 == 1 ? "Second" : "First") << endl;
}
