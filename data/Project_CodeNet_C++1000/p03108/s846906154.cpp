//#define _GLIBCXX_DEBUG
#include<bits/stdc++.h>

using namespace std;


inline void print() {
    cout << endl;
}
template <typename First, typename... Rest>
void print(const First &first, const Rest &... rest) {
    cout << first << ' ';
    print(rest...);
}


struct UnionFind {
    vector<int> par;
    vector<int> rank;
    vector<int> siz;

    UnionFind (int n = 1 ) {
        init(n);
    }

    void init(int n = 1) {
        par.resize(n); rank.resize(n); siz.resize(n);
        for (int i = 0; i < n; i++) par[i] = i, rank[i] = 0, siz[i] = 1;
    }

    int root(int x) {
        if (par[x] == x) {
            return x;
        }
        else {
            int r = root(par[x]);
            return par[x] = r;
        }
    }

    bool same(int x, int y) {
        return root(x) == root(y);
    }

    void unite(int x, int y) {
        x = root(x);
        y = root(y);
        if (x == y) return;

        if (rank[x] < rank[y]) {
            par[x] = y;
            siz[y] += siz[x];
        }
        else {
            par[y] = x;
            siz[x] += siz[y];
            if (rank[x] == rank[y]) rank[x]++;
        }
    }

    int size(int x) {
        return siz[root(x)];
    }
};



long long COM(long long n, long long k) {
    long long mul = 1;
    long long div = 1;
    for (long long i = 0; i < k; i++) {
        mul = (mul * (n - i));
        div = (div * (i + 1));
    }
    return mul / div;
}


void solve() {
    int N, M; cin >> N >> M;
    vector<pair<int, int>> bridge(M);
    for (int i = 0; i < M; i++) {
        int A, B; cin >> A >> B; 
        A--; B--;
        bridge[i] = make_pair(A, B);
    }

    UnionFind uf(N);

    vector<long long> ans(M+1);

    ans[M] = COM(N, 2);

    for (int i = M-1; i >= 0; i--) {
        int A = bridge[i].first, B = bridge[i].second;
        
        //print(uf.size(A), uf.size(B));

        if (uf.same(A, B)) {
            ans[i] = ans[i+1];
        }
        else {
            ans[i] = ans[i+1] - uf.size(A) * uf.size(B);
        }
        
        uf.unite(A, B);
    }

    for (int i = 1; i < M+1; i++) cout << ans[i] << endl;
    
}


int main() {
    solve();
    return 0;
}