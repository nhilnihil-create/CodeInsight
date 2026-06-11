#include <bits/stdc++.h>

using namespace std;

struct WeightUniTree {
    int *par, *rank, *diff_weight;

    WeightUniTree(int n) {
        par = new int[n];
        rank = new int[n];
        diff_weight = new int[n];
        for(int i = 0; i < n; i++) {
            par[i] = i;
            rank[i] = 0;
            diff_weight[i] = 0;
        }
    }

    int root(int x) {
        if(par[x] == x) return x;
        int r = root(par[x]);
        diff_weight[x] += diff_weight[par[x]];
        return par[x] = r;
    }

    int weight(int x) {
        root(x);
        return diff_weight[x];
    }

    int diff(int x, int y) {
        return weight(y) - weight(x);
    }

    void merge(int x, int y, int w) {
        w += weight(x);
        w -= weight(y);
        x = root(x);
        y = root(y);
        if(x == y) return;
        if(rank[x] < rank[y]) {
            par[x] = y;
            diff_weight[x] = -w;
        }else {
            par[y] = x;
            if(rank[x] == rank[y]) rank[x]++;
            diff_weight[y] = w;
        }
    }
    
    bool same(int x, int y) {
        return root(x) == root(y);
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    WeightUniTree tree(n);

    bool flag = true;
    for(int i = 0; i < m; i++) {
        int l, r, d;
        cin >> l >> r >> d;
        if(tree.same(l - 1, r - 1) && tree.diff(l - 1, r - 1) != d) {
            flag = false;
            break;
        }
        tree.merge(l - 1, r - 1, d);
    }
    cout << (flag? "Yes" : "No") << endl;

    return 0;
}
