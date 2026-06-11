#include <bits/stdc++.h>

using namespace std;

#define int long long
const double PI = 3.14159265358979323846;
typedef vector<int> vint;
typedef pair<int, int> pint;
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
// cout << fixed << setprecision(20);

// ポテンシャルつきUnionFindTree
// T: 可換群
template<typename T>
class UnionFindTreeWithPotential {
    const int n;
    std::vector<int> par, size;
    std::vector <T> diff_potential;
public:
    // 要素数と加法単位元を指定して初期化
    UnionFindTreeWithPotential(int n) : n(n), par(n), size(n), diff_potential(n) {
        for (int i = 0; i < n; i++) {
            par[i] = i;
            size[i] = 1;
            diff_potential[i] = T();
        }
    }

    // 要素iが属する集合を表す木の根を求める
    int getRoot(int i) {
        if (par[i] == i) {
            return i;
        } else {
            int r = getRoot(par[i]);
            diff_potential[i] += diff_potential[par[i]];
            return par[i] = r;
        }
    }

    // 要素iのポテンシャル
    T getPotential(int i) {
        getRoot(i);
        return diff_potential[i];
    }

    // 要素iと要素jのポテンシャル差
    T getDiff(int i, int j) {
        return getPotential(j) - getPotential(i);
    }

    // getDiff(i, j) = dとなるように要素iと要素jの属する集合を併合
    void unite(int i, int j, T d) {
        d -= getDiff(i, j);
        i = getRoot(i);
        j = getRoot(j);
        if (i == j)return;
        if (size[i] < size[j])swap(i, j), d = -d;
        par[j] = i;
        size[i] += size[j];
        diff_potential[j] = d;
    }

    // 要素iと要素jが同じ集合に属するか否か
    bool isSame(int i, int j) {
        return getRoot(i) == getRoot(j);
    }

    // 要素iが属する集合の大きさ
    int getSize(int i) {
        return size[getRoot(i)];
    }
};

int N, M;
int L[220000], R[220000], D[220000];

signed main() {
    cin >> N >> M;
    UnionFindTreeWithPotential<int> uf(N + 1);
    for (int i = 0; i < M; i++) {
        cin >> L[i] >> R[i] >> D[i];
        if (uf.isSame(L[i], R[i])) {
            if (uf.getDiff(L[i], R[i]) != D[i]) {
                cout << "No" << endl;
                return 0;
            }
        } else {
            uf.unite(L[i], R[i], D[i]);
        }
    }
    cout << "Yes" << endl;
}
