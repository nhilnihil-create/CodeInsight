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

using P = pair<int, int>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int k;
    cin >> k;
    vector<vector<edge>> g(k);
    for(int i = 0; i < k; i++) {
        g[i].emplace_back(edge{(i + 1) % k, 1});
        g[i].emplace_back(edge{i * 10 % k, 0});
    }
    vector<int> d(k, INF);
    d[1] = 0;
    priority_queue<P, vector<P>, greater<P>> que;
    que.emplace(P(0, 1));
    while(!que.empty()) {
        int nd = que.top().first;
        int from = que.top().second;
        que.pop();
        if(nd > d[from]) {
            continue;
        }
        for(const auto &e : g[from]) {
            if(d[e.to] > d[from] + e.cost) {
                d[e.to] = d[from] + e.cost;
                que.emplace(P(d[e.to], e.to));
            }
        }
    }
    print(d[0] + 1);
}