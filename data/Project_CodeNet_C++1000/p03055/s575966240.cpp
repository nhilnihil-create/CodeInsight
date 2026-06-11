#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define PI 3.141592653589793
#define rep(i, N) for (int i = 0; i < (N); i++)
#define REP(i, a, N) for (int i = a; i < (N); i++)
#define rrep(i, N, k) for (int i = (N); i >= (k); i--);
#define all(x) (x).begin(), (x).end()
#define vi vector<int>
#define pi pair<int, int>
#define pl pair<ll, ll>
template<class T> istream &operator>>(istream&is,vector<T>&v){for(auto &elemnt:v)is>>elemnt;return is;}
template<class T,class U> istream &operator>>(istream&is,pair<T,U>&p){is>>p.first>>p.second;return is;}
template<class T>vector<T> make_vector(size_t a){return vector<T>(a);}
template<class T, class... Ts>auto make_vector(size_t a, Ts... ts){return vector<decltype(make_vector<T>(ts...))>(a, make_vector<T>(ts...));}
const int MOD = 1e9+ 7;
const int INF = numeric_limits<int>::max() - (int)1e8;
const ll INFLL = numeric_limits<ll>::max() - (ll)1e17;

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

template< typename T >
pair< T, int > dfs(const WeightedGraph< T > &g, int idx, int par) {
    pair< T, int > ret(0, idx);
    for(auto &e : g[idx]) {
        if(e.to == par) continue;
        auto cost = dfs(g, e.to, idx);
        cost.first += e.cost;
        ret = max(ret, cost);
    }
    return ret;
}

template< typename T >
T tree_diameter(const WeightedGraph< T > &g) {
    auto p = dfs(g, 0, -1);
    auto q = dfs(g, p.second, -1);
    return (q.first);
}


int main() {
    int N;
    cin >> N;
    WeightedGraph<int> G(N);
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        G[a].emplace_back(b, 1);
        G[b].emplace_back(a, 1);
    }
    cout << (tree_diameter(G) % 3 == 1 ? "Second" : "First") << endl;
}