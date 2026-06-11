#include <iostream>
#include <vector>
#include <set>
#include <map>

using namespace std;

typedef long long ll;

class union_find {
    vector<int> par, sz;

public:
    union_find(int n) {
        par.resize(n);
        sz.resize(n, 0);
        for (int i = 0; i < n; i++)
            par[i] = i;
    }

    int find(int x) {
        if (par[x] == x)
            return x;
        else 
            return par[x] = find(par[x]);
    }

    void unite(int x, int y) {
        x = find(x), y = find(y);

        if (sz[y] > sz[x])
            par[x] = y;
        else
        {
            par[y] = x;
            if (sz[x] == sz[y])
                sz[x]++;
        }
    }

    bool same(int x, int y) {
        return find(x) == find(y);
    }
};

int main() {
    int n, m;   cin >> n >> m;
    union_find uf(n);
    vector<int> a(m), b(m);
    for (int i = 0; i < m; i++) {
        cin >> a[i] >> b[i];
        a[i]--, b[i]--;
    }


    vector<long long> cnt(n, 1);
    vector<long long> tmp(m+1); //i回目の崩壊後に連結な島の組の数
    tmp[m] = 0;
    for (int i = m-1; i >= 0; i--) {
        a[i] = uf.find(a[i]);
        b[i] = uf.find(b[i]);
        if (uf.same(a[i], b[i])) {
            tmp[i] = tmp[i+1];
            continue;
        }
        uf.unite(a[i], b[i]);
        tmp[i] = tmp[i+1] + cnt[a[i]] * cnt[b[i]];
        if (uf.find(b[i]) == a[i])
            swap(a[i], b[i]);
        
        cnt[b[i]] += cnt[a[i]];
        cnt[a[i]] = 0;
    }
    
    for (int i = 0; i < m; i++) 
        cout << tmp[0] - tmp[i+1] << endl;
    return 0;
}
