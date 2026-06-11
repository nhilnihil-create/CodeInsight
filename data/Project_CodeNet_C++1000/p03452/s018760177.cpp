#include <bits/stdc++.h>

using namespace std;

#define llong long long int
#define ldouble long double
#define rep(i, n) for (size_t i = 0; i < n; ++i)
#define all(x) x.begin(), x.end()
#define stl_rep(itr, x) for (auto itr = x.begin(); itr != x.end(); ++itr)

const static int MOD = 1000000000 + 7;
const static llong INF = 1LL << 60;
const static int dy[] = {0, 1, 0, -1};
const static int dx[] = {1, 0, -1, 0};

struct PUF { // 参考 : https://qiita.com/drken/items/cce6fc5c579051e64fab
    vector<int> par;
    vector<int> rank;
    vector<int> diff_weight;

    PUF(int n) {
        par.resize(n);
        rank.resize(n);
        diff_weight.resize(n);
        rep(i, n) par[i] = i, rank[i] = 0, diff_weight[i] = 0;
    }

    int root(int x) {
        if (par[x] == x) {
            return x;
        }
        else {
            int r = root(par[x]);
            diff_weight[x] += diff_weight[par[x]];
            return par[x] = r;
        }
    }

    int weight(int x) {
        root(x);
        return diff_weight[x];
    }

    bool issame(int x, int y) {
        return root(x) == root(y);
    }

    bool merge(int x, int y, int w) {
        w += weight(x); w -= weight(y);
        x = root(x); y = root(y);
        if (x == y) return false;
        if (rank[x] < rank[y]) swap(x, y), w = -w;
        if (rank[x] == rank[y]) ++rank[x];
        par[y] = x;
        diff_weight[y] = w;
        return true;
    }

    int diff(int x, int y) {
        return weight(y) - weight(x);
    }
};

int main (int argc, char *argv[]) {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    
    PUF people(n);
    rep(i, m) {
        int l, r, d;
        cin >> l >> r >> d;
        --l, --r;
        if (people.issame(l, r)) {
            if (people.diff(l, r) != d) {
                cout << "No" << endl;
                return 0;
            }
        } else {
            people.merge(l, r, d);
        }
    }

    cout << "Yes" << endl;

    return 0;
}