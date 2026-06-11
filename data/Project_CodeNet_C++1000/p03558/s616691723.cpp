#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
const ull mod = 1e9 + 7;
const int INFINT = INT_MAX/2;
#define REP(i,n) for(int i=0;i<(int)n;++i)

//debug
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;

template < typename T >
void vprint(T &v){
	REP(i, v.size()){
		cout << v[i] << " ";
	}
	cout << endl;
}

struct Edge{
    int dst;
    int weight;
    Edge(int dst, int weight): dst(dst), weight(weight) {}
};

struct TmpDist{
    int vertex;
    int dist;
    TmpDist(int vertex, int dist): vertex(vertex), dist(dist) {}
    bool operator< (const TmpDist& right)const{
        return dist > right.dist;
    }
};

typedef vector<Edge> Edges;
typedef vector<Edges> Graph;

vector<int> dijkstra(Graph &G, int r){
    int V = G.size();
    vector<int> dist(V, INFINT);
    priority_queue<TmpDist> pq;
    vector<bool> check(V, false);
    TmpDist init(r, 0);
    pq.push(init);
    while(!pq.empty()){
        TmpDist td = pq.top();pq.pop();
        int now = td.vertex;
        if(!check[now]){
            check[now] = true;
            dist[now] = td.dist;
            for (int i=0;i<G[now].size();i++){
                if(dist[G[now][i].dst] > td.dist + G[now][i].weight){
                    TmpDist tdCandidate(G[now][i].dst, td.dist + G[now][i].weight);
                    pq.push(tdCandidate);
                }
            }
        }
    }
    return dist;
}

int main(){
	int K;
	cin >> K;

	Graph G(K);
	REP(i, K){
		Edge e((i+1)%K, 1);
		Edge f((10*i)%K, 0);
		G[i].push_back(e);
		G[i].push_back(f);
	}

	auto dist = dijkstra(G, 1);
	cout << dist[0]+1 << endl;
	//vprint(dist);
    return 0;
}