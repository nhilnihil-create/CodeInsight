#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

#define vi vector<int>
#define vl vector<long long>
#define vvi vector< vector<int> >
#define vvl vector< vector<ll> >
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define REPD(i, n) for (int i = (int)(n-1); i >= 0; i--)
#define FOR(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define FORD(i, a, b) for (int i = (int)(a); i >= (int)(b); i--)
#define INF 1e18
#define INFTY 1e9
#define MOD 1e9+7
#define SIZE_OF_ARRAY(array) (sizeof(array)/sizeof(array[0]))

template<class T> bool chmax(T &a, const T & b) {
    if (a<b) {
        a = b;
        return true;
    }
    return false;
}

template<class T> bool chmin(T &a, const T & b) {
    if (a>b) {
        a = b;
        return true;
    }
    return false;
}

struct edge {int to, cost;};
vector< vector<edge> > es;
const int MAX_N = 10010;

struct UnionFind {

    vector<int> par;
    vector<int> rank;
    vector<int> size;

    UnionFind(int N) : par(N), rank(N), size(N) {
        REP(i, N) {
            par[i] = i;
            rank[i] = 0;
            size[i] = 1;
        }
    }
    
    int find(int x) {
        if (par[x] == x) return x;
        else return par[x] = find(par[x]);
    }

    void unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (rank[x] > rank[y]) {
            par[y] = x;
            size[x] += size[y];
        } else {
            par[x] = y;
            size[y] += size[x];
            if (rank[x] == rank[y]) rank[y]++;
        }
    }

    bool same(int x, int y) {
        return find(x) == find(y);
    }

    int ret_size(int x) {
        return size[find(x)];
    }
};

bool comp(const edge& e1, const edge& e2) {
    return e1.cost < e2.cost;
}

int main() {
    int N, M;
    cin >> N >> M;
    vi A, B;
    A.resize(M);
    B.resize(M);
    REP(i, M) {
        cin >> A[i] >> B[i];
        --A[i]; --B[i];
    }
    int res = 0;
    REP(i, M) {
        UnionFind uf(N);
        REP(j, M) {
            if (i == j) continue;
            uf.unite(A[j], B[j]);
        }
        if (!uf.same(A[i], B[i])) res += 1;
    }

    cout << res << endl;
    return 0;
}