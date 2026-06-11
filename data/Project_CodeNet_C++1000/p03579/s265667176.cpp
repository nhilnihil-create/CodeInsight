/*
* Welcome to my code!
*---------------------------------------------*
* author : lynmisakura(twitter : @andoreiji11)
*/

#include <iostream>
#include <limits.h>
#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <list>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <cassert>

using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define rrep(i,n) for(int i=n-1;i>=0;i--)
#define repn for(int i = 0;i < n;i++)
#define ain(a) for(auto& i : a)cin >> i;
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x.size()) 
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define cont continue

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using pi = pair<int,int>;
using vpi = vector<pi>;
using pl = pair<ll,ll>;
using vpl = vector<pl>;

template<class T> bool chmin(T& a,T b){if(a > b){a = b;return true;}else return false;}
template<class T> bool chmax(T& a,T b){if(a < b){a = b;return true;}else return false;}
template<class T> void print(std::vector<T> a){ int sz = a.size();
for(int i=0;i<a.size();i++)cout << a[i] << (i < sz-1 ? ' ' : '\n'); }
void ioboost(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(20);}
///////////////////////////////////////////////////////////

template<class T> struct Edge{

	int to;
	T cost;

	Edge(int t = 0,T c = 1):to(t),cost(c){}

};
template<class T> struct Graph{
	
	int N,M;
	vector<vector<Edge<T> > > g;

	Graph(int N,int M):N(N),M(M),g(N,vector<Edge<T> >(0)){}

	void add_edge(int a,int b,T c = 1){
		g[a].emplace_back(b,c);
	}

};

template<class T> struct Bipartite{

	Graph<T> G;
	bool is_bipartite = true;
	vector<int> col;
	long long cnt[2] = {0,0};

	Bipartite(Graph<T>& G):G(G),col(G.N, -1){}

	void dfs(int x,int c = 0){
		col[x] = c;
		cnt[c]++;
		for(auto e : G.g[x]){
			if(col[e.to] >= 0){
				if(col[e.to] == c){
					is_bipartite = false;
					return;
				}
			}else{
				dfs(e.to,c^1);
			}
		}
	}
	bool solve(){
		dfs(0);	
		return is_bipartite;
	}
};


int main(int argc, char const *argv[])
{
	ll n,m;cin >> n >> m;

	Graph<int> G(n,m);
	rep(i,m){
		int a,b;cin >> a >> b;
		a--,b--;
		G.add_edge(a,b);
		G.add_edge(b,a);
	}

	Bipartite<int> B(G);

	B.solve();

	if(B.is_bipartite){
		cout << B.cnt[0]*B.cnt[1] - m << '\n';
	}else{
		cout << n*(n-1)/2 - m << '\n';
	}

}
