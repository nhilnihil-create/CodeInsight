#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <stack>
#include <queue>
#include <complex>
#include <set>
#include <list>
#include <iomanip>
#include <map>
#include <memory.h>
#include <iterator>


using namespace std;
static const double EPS = 1e-9;
typedef long long ll;
typedef unsigned long long ull;
#define FOR(i,n) for(int i=0;i<(int)n;++i)
#define FORNUM(p, x) for (int num = p; num < (int)(x); ++num)
#define FORI(p, x) for (int i = p; i < (int)(x); ++i)
#define FORJ(p, x) for (int j = p; j < (int)(x); ++j)
#define FORK(p, x) for (int k = p; k < (int)(x); ++k)
#define FORL(p, x) for (int l = p; l < (int)(x); ++l)

typedef pair<int,int>P;
#define INF 1000000000
 

 
int V,E;

struct edge {
	int dst;
	int cost;
	edge(int dst, int cost) {
		this->dst = dst; this->cost = cost;
	}

};

typedef vector<edge> edges;
vector<edges> G;

int dist[100005];
int k;

void solve(int v) {

	fill(dist, dist + k, INF);
	dist[v] = 0;
	deque<int> q;
	
	q.push_front(v);
	while (q.size()) {
		int v = q.front(); q.pop_front();
		
		FORI(0,G[v].size()) {
			edge e = G[v][i];
			if (dist[e.dst] > dist[v] + e.cost) {
				dist[e.dst] = dist[v] + e.cost;
				if(e.cost==0)
					q.push_front(e.dst);
				else
					q.push_back(e.dst);
			}
		}
	}
	cout << dist[0] + 1 << endl;
}

int main() {
	cin >> k;
	G.resize(k);
	FORI(0, k) {
		G[i].push_back(edge((i + 1)%k, 1));
		G[i].push_back(edge((i*10)%k, 0));
	}
	solve(1);
	return 0;
}
