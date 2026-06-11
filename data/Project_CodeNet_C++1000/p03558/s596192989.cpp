#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <bitset>
#include <limits>
#include <random>
#include <complex>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cassert>
using namespace std;

#define REP(i,n) for (int i = 0; i < n; i++)
template <class T> using reversed_priority_queue = priority_queue<T, vector<T>, greater<T> >;
typedef long long ll;

template <class T> struct Dijkstra {

    struct Edge{
        int to;
        T cost;
        Edge(int _to, T _cost) : to(_to), cost(_cost) {}
    };
    
    const T INF = numeric_limits<T>::max() / 2;
    vector< vector< Edge > > G;
    vector< T > d;
    Dijkstra (int n) : G(n), d(n) {}

    void add_directed_edge(int a, int b, T c) {
        G[a].push_back(Edge(b,c));
    }
    
    void add_undirected_edge(int a, int b, T c) {
        G[a].push_back(Edge(b,c));
        G[b].push_back(Edge(a,c));
    }

    void init(int s) {
        priority_queue< pair<T,int>,vector< pair<T,int> >, greater< pair<T,int> > > que;
        fill(d.begin(), d.end(), INF);
        d[s] = 0;
        que.push(make_pair(0,s));
        while (!que.empty()){
            pair<T,int> p = que.top();
            que.pop();
            int v = p.second;
            if (d[v] < p.first) continue;
            for (int i = 0; i < G[v].size(); i++) {
                Edge e = G[v][i];
                if (d[e.to] > d[v] + e.cost) {
                    d[e.to] = d[v] + e.cost;
                    que.push(make_pair(d[e.to],e.to));
                }
            }
        }
    }
    
    T dist(int a) {
        return d[a];
    }
    
}; 


int main () 
{
    int K; cin >> K;
    Dijkstra < int > inst(100010);

    for (int i = 1; i < K; i++) {
        inst.add_directed_edge(i, (i + 1) % K, 1);
        inst.add_directed_edge(i, (i * 10) % K, 0);
    }

    inst.init(1);

    cout << 1 + inst.dist(0) << endl;

    return 0;
}
