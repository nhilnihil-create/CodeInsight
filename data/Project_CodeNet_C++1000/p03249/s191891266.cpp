#include "bits/stdc++.h"
using namespace std;
template <typename T> void read(T& t){ cin >> t; }
template <typename T, typename ... U> void read(T& t, U& ... u){ read(t); read(u ...); }
template <typename T> void write(T t){ cout << t; }
template <typename T, typename ... U> void write(T t, U ... u){ write(t); write(u ...); }
//#define int long long
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define size(x) (int)x.size()
#define all(x) x.begin(),x.end()
#define FOR(i,a,b) for(int i=a; i<=b; ++i)
#define ROF(i,b,a) for(int i=b; i>=a; --i)
#define LL long long
using pii = pair<int,int>;
const int INF = 2e9;
const int NN = 1e5 + 3;

int n;
set<LL> s;
map<LL,int> id;
map<int,LL> dist, dist2;
int sz[NN];
vector<pii> e;
vector<int> adj[NN];

void checkConn(int u, set<int> &visited){
	visited.insert(u);
	for(int v: adj[u]) if(!visited.count(v)) checkConn(v, visited);
}

LL getDistSum(int u, int prv, int d){
	LL sum = 0;
	sum += d;
	for(int v: adj[u]) if(v != prv) sum += getDistSum(v, u, d+1);
	return sum;
}

void distributeDistSum(int u, int prv, LL sum){
	dist2[u] = sum;
	for(int v: adj[u]) if(v != prv) distributeDistSum(v, u, sum - sz[v] + (n-sz[v]));
}

int32_t main(){ FAST;
	read(n);
	FOR(i,1,n){ LL d; read(d); s.insert(d); id[d] = i; dist[i] = d; }

	if(n == 2 || n == 3 || n == 4){
		write(-1, "\n");
		return 0;
	}

	FOR(i,1,n) sz[i] = 1;
	ROF(cnt,n,2){
		LL d = *rbegin(s);
		s.erase(d);
		int i = id[d];

		LL nxtD = d + sz[i] - (n-sz[i]);
		if(!s.count(nxtD)){
			write(-1, "\n");
			return 0;
		}

		int j = id[nxtD];
		e.emplace_back(i,j);
		sz[j] += sz[i];
	}

	for(pii edg: e){
		int u,v; tie(u,v) = edg;
		adj[u].emplace_back(v);
		adj[v].emplace_back(u);
	}

	int root = -1;
	FOR(i,1,n) if(sz[i] == n) root = i;
	if(root == -1){
		write(-1, "\n");
		return 0;
	}
	
	set<int> visited;
	checkConn(root, visited);
	if(!(size(visited) == n)){
		write(-1, "\n");
		return 0;
	}

	LL sum = getDistSum(root,root,0);

	distributeDistSum(root,root,sum);

	bool different = false;
	for(auto el: dist) if(dist[el.first] != dist2[el.first]) different = true;
	for(auto el: dist2) if(dist[el.first] != dist2[el.first]) different = true;
	if(different){
		write(-1, "\n");
		return 0;
	}

	for(pii edg: e) write(edg.first, " ", edg.second, "\n");
}