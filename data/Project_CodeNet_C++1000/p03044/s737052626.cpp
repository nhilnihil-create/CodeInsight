#include <bits/stdc++.h>
using namespace std;
template <class T> inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T> inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return 1;
    }
    return 0;
}
void print() { cout << "\n"; }
template <class T> void print(const T &x) { cout << x << "\n"; }
template <class T, class... Args> void print(const T &x, const Args &... args) {
    cout << x << " ";
    print(args...);
}
template <class T> void printVector(const vector<T> &v) {
    for(const T &x : v) {
        cout << x << " ";
    }
    cout << "\n";
}
using ll = long long;

#define ALL(v) (v).begin(), (v).end()
#define RALL(v) (v).rbegin(), (v).rend()
const double EPS = 1e-7;
const int INF = 1 << 30;
const ll LLINF = 1LL << 60;
const double PI = acos(-1);
constexpr int MOD = 1000000007;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

//-------------------------------------

struct edge {
    int to, cost;
};

int n;
vector<vector<edge>> g;
vector<int> color;

void dfs(int v, int p, int c) {
    color[v] = c;
    for(const auto &e : g[v]) {
        if(e.to != p) {
            dfs(e.to, v, (e.cost & 1) ? 1 - c : c);
        }
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n;
    g.resize(n);
    color.resize(n, -1);
    for(int i = 0; i < n - 1; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        g[--a].emplace_back(edge{--b, c});
        g[b].emplace_back(edge{a, c});
    }
    dfs(0, -1, 0);
    for(int i = 0; i < n; i++) {
        print(color[i]);
    }
}