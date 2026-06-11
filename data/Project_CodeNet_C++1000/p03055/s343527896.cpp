#include <bits/stdc++.h>
using namespace std;
using Int = int_fast64_t;

Int n;
class edge{
public:
	Int cost;
	size_t from, to;
	edge(Int c, size_t f, size_t t){
		cost = c;
		from = f;
		to = t;
	}
};
using edges = vector<edge>;
using graph = vector<edges>;
void readgraph(graph &g, size_t E, bool D, bool C, bool Z){ // E:num_of_edges, D:directed, C:costed, Z:already 0-indexed
	for(size_t i=0; i<E; ++i){
		edge e(1, 0, 0);
		if(!C) cin >> e.from >> e.to;
		else cin >> e.from >> e.to >> e.cost;
		if(!Z){
			--e.from;
			--e.to;
		}
		g[e.from].push_back(e);
		if(!D){
			swap(e.from, e.to);
			g[e.from].push_back(e);
		}
	}
}
void calc_distance(graph &g, vector<Int> &d, Int s){
	d.assign(g.size(), 1e8);
//	for(Int i=0; i<n; ++i)
//		cout << d[i] << " \n"[i+1==n];
	d[s] = 0;
	queue<Int> q;
	q.push(s);
	while(!q.empty()){
		Int p = q.front(); q.pop();
		for(auto e:g[p])
			if(d[e.to] == 1e8){
				d[e.to] = d[p]+1;
				q.push(e.to);
			}
	}
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> n;
	graph g(n);
	readgraph(g, n-1, false, false, false);
	vector<Int> d(n);
	calc_distance(g, d, 0);
	Int l=0;
	for(Int i=0; i<n; ++i)
		if(d[i] > d[l])
			l = i;
//	for(Int i=0; i<n; ++i)
//		cout << i << "  " << d[i] << "\n";
	calc_distance(g, d, l);
	Int r = 0;
	for(Int i=0; i<n; ++i)
		r = max(r, d[i]);
//	for(Int i=0; i<n; ++i)
//		cout << i << "  " << d[i] << "\n";
//	for(Int i=0; i<n; ++i)
//		for(Int j=0; j<g[i].size(); ++j)
//			cout << g[i][j].to << " \n"[j+1==g[i].size()];
//	cout << l << " " << r << "\n";
	if(r % 3 == 1) cout << "Second\n";
	else cout << "First\n";
}