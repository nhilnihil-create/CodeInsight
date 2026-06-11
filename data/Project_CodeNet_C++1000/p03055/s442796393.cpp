#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
using WGraph = vector<vector<pair<int, ll>>>;

template<class T>inline bool chmax(T &a, const T &b) { if (b > a) { a = b; return true; } return false; }
template<class T>inline bool chmin(T &a, const T &b) { if (b < a) { a = b; return true; } return false; }

constexpr int dx[4] = {-1, 0, 0, 1}, dy[4] = {0, -1, 1, 0};
constexpr int INF = 1e9;
constexpr int MOD = 1e9 + 7;
constexpr long long LINF = 1e18;
constexpr double EPS = 1e-10;
constexpr double PI = M_PI;

int diameter(const Graph &G) {
    int n = (int)G.size();
    vector<int> dis(n, -1);
    dis.at(0) = 0;
    queue<int> que;
    que.push(0);
    while (!que.empty()) {
        int cur = que.front(); que.pop();
        for (int nx : G.at(cur)) {
            if (dis.at(nx) == -1) {
                dis.at(nx) = dis.at(cur) + 1;
                que.push(nx);
            }
        }
    }
    int maxi = -1, ind = -1;
    for (int i=0; i<n; ++i) if (chmax(maxi, dis.at(i))) ind = i;

    dis.assign(n, -1);
    dis.at(ind) = 0;
    que.push(ind);
    while (!que.empty()) {
        int cur = que.front(); que.pop();
        for (int nx : G.at(cur)) {
            if (dis.at(nx) == -1) {
                dis.at(nx) = dis.at(cur) + 1;
                que.push(nx);
            }
        }
    }
    int res = -1;
    for (int i=0; i<n; ++i) chmax(res, dis.at(i));
    return res;
}

void solve() {
    int n;
    cin >> n;
    Graph G(n);
    for (int i=0; i<n-1; ++i) {
        int a, b;
        cin >> a >> b;
        G.at(a-1).push_back(b-1);
        G.at(b-1).push_back(a-1);
    }

    int dia = diameter(G);
    if (dia%3 == 1) cout << "Second" << '\n';
    else cout << "First" << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(20);

    solve();

    return 0;
}
