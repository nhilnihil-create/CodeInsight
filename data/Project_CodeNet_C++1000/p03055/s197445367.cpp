#include <bits/stdc++.h>
using namespace std;

struct Benri { Benri() { std::cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(12);}} benri;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using vll = vector<long long>;
using vvll = vector<vll>;
using pll = pair<ll, ll>;
using ull = unsigned long long;

template <typename T> using PQ = priority_queue<T>;
template <typename T> using minPQ = priority_queue<T, vector<T>, greater<T>>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define mp make_pair
#define F first
#define S second

template<class T>bool chmax(T &a, const T &b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b < a) { a = b; return 1; } return 0; }

constexpr long long MOD = 1000000007;
//constexpr long long MOD = 998244353;
//constexpr int INF = 1001001001;
constexpr ll INF = 1001001001001001001ll;
constexpr double EPS = 1e-10;
using number = long long;


using Graph = vector<vector<int>>;

struct Diameter {
    vector<int> prev;

    pii DiameterDFS(const Graph &G, int v, int p) {
        pii res(v, 0);
        for (int i = 0; i < (int)G[v].size(); ++i) {
            if (G[v][i] == p) continue;
            pii tmp = DiameterDFS(G, G[v][i], v);
            tmp.second++;
            if (tmp.second > res.second) res = tmp, prev[G[v][i]] = v;
        }
        return res;
    }

    vector<int> solve(const vector<vector<int> > &G) {
        prev.assign((int)G.size(), -1);
        pii leaf = DiameterDFS(G, 0, -1);

        prev.assign((int)G.size(), -1);
        pii t = DiameterDFS(G, leaf.first, -1);
        vector<int> res;
        int cur = t.first;
        while (cur != -1) res.push_back(cur), cur = prev[cur];
        return res;
    }
};

int N;
Graph G(200005, vi());

int main() {
    cin >> N;
    rep(i, N - 1) {
        int a, b; cin >> a >> b;
        a--, b--;
        G[a].pb(b);
        G[b].pb(a);
    }

    Diameter diam;
    vi res = diam.solve(G);
    int x = res.size();

    cout << (x % 3 == 2 ? "Second" : "First") << endl;

}