#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef vector<int> VI;

template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
#define _overload3(_1,_2,_3,name,...) name
#define _rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)
#define rep(...) _overload3(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)
#define all(x) (x).begin(),(x).end()



template< typename T >
struct edge {
  int src, to;
  T cost;

  edge(int to, T cost) : src(-1), to(to), cost(cost) {}

  edge(int src, int to, T cost) : src(src), to(to), cost(cost) {}

  edge &operator=(const int &x) {
    to = x;
    return *this;
  }

  operator int() const { return to; }
};

template< typename T >
using Edges = vector< edge< T > >;
template< typename T >
using WeightedGraph = vector< Edges< T > >;
using UnWeightedGraph = vector< vector< int > >;
template< typename T >
using Matrix = vector< vector< T > >;


int main() {
    int n;
    cin >> n;
    WeightedGraph<int> G(n);
    rep (i, n-1) {
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        w %= 2;
        G[u].emplace_back(v, w);
        G[v].emplace_back(u, w);
    }
    vector<int> ans(n, -1);
    ans[0] = 0;
    queue<int> Q;
    Q.push(0);
    while(Q.size()) {
        int f = Q.front();
        Q.pop();
        for (auto e: G[f]) {
            int to = e.to;
            int weight = e.cost;
            if (ans[to] != -1) {
                continue;
            }
            if (weight == 0) {
                ans[to] = ans[f];
            } else {
                ans[to] = 1 - ans[f];
            }
            Q.push(to);
        }
    }
    rep (i, n) {
        cout << ans[i] << endl;
    }
}

