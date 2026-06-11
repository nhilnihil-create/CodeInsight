#include <bits/stdc++.h>
using namespace std;

template <typename A, typename B>
string to_string(pair<A, B> p);

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p);

template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p);

string to_string(const string& s) {
    return '"' + s + '"';
}

string to_string(const char* s) {
    return to_string((string) s);
}

string to_string(bool b) {
     return (b ? "true" : "false");
}

string to_string(vector<bool> v) {
    bool first = true;
    string res = "{";
    for (int i = 0; i < static_cast<int>(v.size()); i++) {
        if (!first) {
            res += ", ";
        }
        first = false;
        res += to_string(v[i]);
    }
    res += "}";
    return res;
}

template <size_t N>
string to_string(bitset<N> v) {
    string res = "";
    for (size_t i = 0; i < N; i++) {
        res += static_cast<char>('0' + v[i]);
    }
    return res;
}

template <typename A>
string to_string(A v) {
    bool first = true;
    string res = "{";
    for (const auto &x : v) {
        if (!first) {
            res += ", ";
        }
            first = false;
            res += to_string(x);
    }
    res += "}";
    return res;
}

template <typename A, typename B>
string to_string(pair<A, B> p) {
    return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p) {
    return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")";
}

template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p) {
    return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";
}

void debug_out() { cerr << endl; }

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
    cerr << " " << to_string(H);
    debug_out(T...);
}
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)

#define rep(i,n) for (int i = 0; i < n; ++i)
#define reps(i,s,n) for (int i = s; i < n; ++i)
#define rep1(i,n) for (int i = 1; i <= n; ++i)
#define all(c) begin(c),end(c)
template<typename T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
template<typename T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
void chmax(string &a, string b) {
    if (a == "-") a = b;
    else if (a.size() < b.size()) a = b;
    else if (a.size() == b.size()) {
        if (a < b) a = b;
    }
}
template<typename T> inline T intceil(T a, T b) { return (a + (b - 1)) / b; }
typedef long long ll;
typedef long double ld;
typedef pair<int,int> PINT;
typedef pair<ll,ll> PLL;
const long long MOD = 1e9+7;
#define precout() cout << std::fixed << std::setprecision(20);
#define print(a) cout << a << endl;
const long long INFLL = (1LL << 62) - 1;
const int INFI = (1 << 30) - 1;
template<typename T> void printv(vector<T>&v) {
    int n = v.size() - 1;
    rep(i, n) cout << v[i] << " ";
    cout << v.back() << endl;
}
static const long double pi = acos(-1.0);
const string alphabet = "abcdefghijklmnopqrstuvwxyz";
const int dy[4] = { 0, 1, 0, -1 };
const int dx[4] = { 1, 0, -1, 0 };

using Graph = vector<vector<int> >;
struct Diameter {
    vector<int> prev;
    pair<int,int> DiameterDFS(const Graph &G, int v, int p) {
        pair<int,int> res(v, 0);
        for (int i = 0; i < (int)G[v].size(); ++i) {
            if (G[v][i] == p) continue;
            pair<int,int> tmp = DiameterDFS(G, G[v][i], v);
            tmp.second++;
            if (tmp.second > res.second) res = tmp, prev[G[v][i]] = v;
        }
        return res;
    }

    vector<int> solve(const vector<vector<int> > &G) {
        prev.assign((int)G.size(), -1);
        pair<int,int> leaf = DiameterDFS(G, 0, -1);
        prev.assign((int)G.size(), -1);
        pair<int,int> t = DiameterDFS(G, leaf.first, -1);
        vector<int> res;
        int cur = t.first;
        while (cur != -1) res.push_back(cur), cur = prev[cur];
        return res;
    }
};

int N;
Graph G;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> N;
    G.assign(N, vector<int>());
    for (int i = 0; i < N-1; ++i) {
        int a, b; cin >> a >> b; --a, --b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    Diameter di;
    auto res = di.solve(G);
    int V = res.size();
    if (V % 3 == 2) cout << "Second" << endl;
    else cout << "First" << endl;
}
