#include <bits/stdc++.h>

using namespace std;
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int i=0;i<(n);i++)
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
constexpr int dx[] = {1, 0, -1, 0, 1, 1, -1, -1};
constexpr int dy[] = {0, -1, 0, 1, 1, -1, -1, 1};

template <typename T> ostream &operator<<(ostream &os, const vector<T> &vec){os << "["; for (const auto &v : vec) {os << v << ","; } os << "]"; return os; }
template <typename T, typename U> ostream &operator<<(ostream &os, const pair<T, U> &p) {os << "(" << p.first << ", " << p.second << ")"; return os;}

// ポテンシャルUF
// 2点間のポテンシャルを指定した併合・ポテンシャル差異の算出を行う
// UFより計算量的には若干重い(各操作: O(log N))
struct PotentialUnionFind {

    vector<int> p;
    vector<ll> w;
    PotentialUnionFind(int n) : p(n, -1), w(n, 0) {
    }

    // uに対するvのポテンシャルの高さをweightとして併合
    // w[v] - w[u] = weight
    // ret: true: 矛盾なし false: 矛盾あり
    // O(log N)
    bool UnionSet(int u, int v, ll weight) {
        int ru = root(u);
        int rv = root(v);
        if (ru == rv) return w[u] - w[v] == weight;
        w[ru] = weight - w[u] + w[v];
        p[rv] += p[ru];
        p[ru] = rv;
        return true;
    }

    // ポテンシャル差異を求める
    // ret: {diff (uからみたvのポテンシャルの高さ), isOK}
    // O(log N)
    pair<ll, bool> find(int u, int v) {
        int ru = root(u);
        int rv = root(v);
        if (ru != rv) return {0, false};
        return {w[u] - w[v], true};
    }

    bool isSame(int u, int v) {
        return root(u) == root(v);
    }

    int size(int x) {
        return -p[root(x)];
    }

    int root(int x) {
        if (p[x] < 0) {
            return x;
        } else {
            int r = root(p[x]);
            w[x] += w[p[x]];
            p[x] = r;
            return r;
        }
    }
};

void solve() {
    int N, M;
    cin >> N >> M;
    PotentialUnionFind uf(N);
    for (int i = 0; i < M; i++) {
        int l, r; ll d;
        cin >> l >> r >> d;
        l--, r--;
        if (!uf.UnionSet(l, r, d)) {
            cout << "No" << endl;
            return;
        }
    }
    cout << "Yes" << endl;
}

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);
    cout.setf(ios::fixed);
    cout.precision(16);
    solve();
    return 0;
}