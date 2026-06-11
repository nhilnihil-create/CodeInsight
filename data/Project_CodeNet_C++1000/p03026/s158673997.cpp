#include <bits/stdc++.h>
#define sort_(a) sort(a.begin(), a.end())
#define rsort(a) sort(a.rbegin(), a.rend())
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, n) for (int i = n - 1; 0 <= i; i--)
#define for_(i, start, end) for (int i = start; i < end; i++)
#define rfor(i, start, end) for (int i = start - 1; 0 <= i; i--)
#define all(a) a.begin(), a.end()
using ll = long long;
using ld = long double;
using namespace std;
constexpr int INF32       = 1'050'000'000;
constexpr long long INF64 = 4'000'000'000'000'000'000;
constexpr int MOD7        = 1'000'000'007;
constexpr int MOD53       = 998'244'353;
constexpr double PI       = 3.14159265358979323846;
template <class T> inline bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template <class T> inline bool chmax(T &a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
void print() { std::cout << '\n'; }
template <class H, class... T> void print(H &&head, T &&... args) {
    std::cout << head;
    sizeof...(args) == 0 ? std::cout << "" : std::cout << ' ';
    print(std::forward<T>(args)...);
}
template <class T> void print(std::vector<T> &v) {
    for (int i = 0; i < v.size(); i++) {
        std::cout << v[i];
        i == v.size() - 1 ? std::cout << '\n' : std::cout << ' ';
    }
}
template <class T> void print(std::vector<std::vector<T>> &v) {
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v[i].size(); j++) {
            std::cout << v[i][j];
            j == v[i].size() - 1 ? std::cout << '\n' : std::cout << ' ';
        }
    }
}
void scan() {}
template <class H, class... T> void scan(H &&head, T &&... args) {
    std::cin >> head;
    scan(std::forward<T>(args)...);
}
template <class T> void scan(std::vector<T> &v) {
    for (auto &&i : v) {
        scan(i);
    }
}

struct graph {
    vector<vector<int>> gph;
    vector<int> indeg, outdeg;
    int vertex;
    graph(int N) : vertex(N) {
        gph.resize(vertex);
        indeg.resize(N);
        outdeg.resize(N);
    }
    // 有向グラフの構築
    void directed_update(int in, int out) {
        gph.at(in).emplace_back(out);
        indeg.at(in)++;
        outdeg.at(out)++;
    }
    // 無向グラフの構築
    void undirected_update(int x, int y) {
        gph.at(x).emplace_back(y);
        gph.at(y).emplace_back(x);
    }
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    scan(N);

    graph g(N);
    rep(i, N - 1) {
        int a, b;
        scan(a, b);
        g.undirected_update(a - 1, b - 1);
    }
    vector<int> c(N);
    scan(c);
    queue<int> que;
    vector<int> ans(N, -1);

    rsort(c);
    rep(i, N) {
        if (g.gph[i].size() == 1) {
            que.push(i);
            ans[i] = c[0];
            break;
        }
    }
    int cnow = 1;

    while (!que.empty()) {
        int now = que.front();
        que.pop();
        rep(i, g.gph[now].size()) {
            int nxt = g.gph[now][i];
            if (ans[nxt] == -1) {
                ans[nxt] = c[cnow++];
                que.push(nxt);
            }
        }
    }
    ll mx = accumulate(all(c), 0) - c[0];
    print(mx);
    print(ans);

    return 0;
}