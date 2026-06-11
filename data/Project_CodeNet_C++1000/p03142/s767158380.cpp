#include <bits/stdc++.h>
#define For(i, a, b) for(int (i)=(a); (i)<(b); ++(i))
#define rFor(i, a, b) for(int (i)=(a)-1; (i)>=(b); --(i))
#define rep(i, n) For((i), 0, (n))
#define rrep(i, n) rFor((i), (n), 0)
#define fi first
#define se second
using namespace std;
typedef long long lint;
typedef pair<int, int> pii;

typedef struct UnionFindTree{
  vector<int> par;
  vector<int> treerank;
  
  UnionFindTree(int n){
    par.resize(n); treerank.resize(n);
    rep(i, n) par[i] = i, treerank[i] = 0;
  }
  
  int find(int x){
    if(par[x] == x) return x;
    return par[x] = find(par[x]);
  }
  
  void unite(int x, int y){
    x = find(x); y = find(y);
    if(x == y) return;
    if(treerank[x] < treerank[y]) swap(x, y);
    if(treerank[x] == treerank[y]) treerank[x]++;
    par[y] = x;
    return;
  }
  
  bool same(int x, int y){
    return find(x) == find(y);
  }
}UF;
 
template<class T> struct edge{
    int from, to; T cost;
    edge(int f, int t, T c){
        from = f; to = t; cost = c;
    }
};
 
template<class T> struct Graph{
    vector<vector<edge<T>>> G;
    int n;
    
    Graph(int n_){
        n = n_;
        G.resize(n);
    }
    
    void add_edge(int f, int t, T c){
        G[f].emplace_back(f, t, c);
    }
    
    vector<T> dijkstra(int s){
        using P = pair<T, int>;
        priority_queue<P, vector<P>, greater<P>> que;
        vector<T> d(n, numeric_limits<T>::max());
        d[s] = 0;
        que.push(P((T)0, s));
        while(!que.empty()){
            P p = que.top(); que.pop();
            int v = p.second;
            if(d[v] < p.first) continue;
            for(edge<T> &e : G[v]){
                if(d[e.to] > d[v] + e.cost){
                    d[e.to] = d[v] + e.cost;
                    que.push(P(d[e.to], e.to));
                }
            }
        }
        return d;
    }
    
    T kruskal(){
        vector<edge<T>> E;
        rep(i, n)for(edge<T> &e: G[i]) E.push_back(e);
        sort(E.begin(), E.end(), [](const edge<T> &e1, const edge<T> &e2){return e1.cost < e2.cost;});
        UF uf(n);
        T res = 0;
        for(edge<T> &e: E){
            if(!uf.same(e.from, e.to)){
                uf.unite(e.from, e.to);
                res += e.cost;
            }
        }
        return res;
    }
    
    void toposo(){
        vector<int> ret(n, -1), in(n, 0);
        rep(i, n)for(edge<T> &e: G[i]) ++in[e.to];
        stack<int> st;
        rep(i, n)if(!in[i]) st.push(i);
        while(!st.empty()){
            int v = st.top(); st.pop();
            for(edge<T> &e: G[v]){
                --in[e.to];
                if(!in[e.to]){
                    st.push(e.to);
                    ret[e.to] = v;
                }
            }
        }
        rep(i, n) printf("%d\n", ret[i]+1);
    }
};

int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    Graph<int> g(n);
    rep(i, n-1+m){
        int a, b;
        scanf("%d%d", &a, &b);
        g.add_edge(a-1, b-1, 0);
    }
    g.toposo();
}