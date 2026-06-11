#include "bits/stdc++.h"
using namespace std;
void __dump(int x){cerr << x;}
void __dump(long long x){cerr << x;}
void __dump(long double x){cerr << fixed << setprecision(3) << x;}
void __dump(char x){cerr << '\'' << x << '\'';}
void __dump(const string &x){cerr << '"' << x << '"';}
void __dump(const char *x){cerr << '"' << x << '"';}
void __dump(bool x){cerr << (x ? "true" : "false");}
void _dump(){cerr << "\n";}
template <typename T, typename U> void __dump(const pair<T, U> &x){cerr << '{'; __dump(x.first); cerr << ','; __dump(x.second); cerr << '}';}
template <typename T, typename U, typename V> void __dump(const tuple<T, U, V> &x){cerr << '{'; __dump(get<0>(x)); cerr << ',';  __dump(get<1>(x)); cerr << ',';  __dump(get<2>(x)); cerr << '}';}
template <typename T> void __dump(const T& x){int f=0; cerr << '{'; for(auto&i:x) cerr << (f++ ? "," : ""), __dump(i); cerr << "}";}
template <typename T, typename ... U> void _dump(T t, U ... u){__dump(t); if(sizeof...(u)) cerr << ", "; _dump(u...);}
#define dump(x ...) cerr  <<  "|| "  <<  # x  <<  "  =  ", _dump(x) 
//#define int long long
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define size(x) (int)x.size()
#define all(x) x.begin(),x.end()
#define ln '\n'
#define __ ' '
#define LL long long
#define LD long double
#define pii pair<int,int>
const int INF = 2e9;
const int NN = 1e5;
int x;
vector<pii> adj[NN+3];
set<pii> ss;
int dist[NN+3];

int main(){ FAST
	cin >> x;

	for(int u=0; u<x; ++u){
		int v1 = (u+1) %x;
		adj[u].emplace_back(v1, 1);

		int v2 = (u*10) %x;
		adj[u].emplace_back(v2, 0);
	}

	for(int u=0; u<x; ++u) dist[u] = INF;
	dist[1] = 1;

	for(int u=0; u<x; ++u) ss.insert({dist[u], u});
	while(!ss.empty()){
		int u, d;
		tie(d, u) = *ss.begin();
		ss.erase(ss.begin());

		if(d > dist[u]) continue;

		for(auto el: adj[u]){
			int v,w;
			tie(v,w) = el;
			if(dist[u] + w < dist[v]){
				dist[v] = dist[u] + w;
				ss.insert({dist[v], v});
			}
		}
	}

	cout << dist[0] << ln;

}