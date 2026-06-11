#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

class union_find {
    vector<long long> par, sz, h;

public:
     union_find(long long n) {
        par.resize(n);
        h.resize(n, 0);
        sz.resize(n,1);
        for (long long i = 0; i < n; i++)
            par[i] = i;
    }

    long long find(long long x) {
        if (par[x] == x)
            return x;
        else 
            return par[x] = find(par[x]);
    }

    void unite(long long x, long long y) {
        x = find(x), y = find(y);
        if (x == y)
            return ;
        
        if (h[x] < h[y])
            swap(x, y);
        
        sz[x] += sz[y];
        sz[y] = sz[x];
        par[y] = x;
        if (h[x] == h[y])
            h[x]++;
    }

    bool same(long long x, long long y) {
        return find(x) == find(y);
    }
    
    int size(long long x) {
        return sz[x] = sz[find(x)];
    }
};

int main() {
    ll n, m;   cin >> n >> m;
    union_find uf(n);
    vector<int> a(m), b(m);
    for (int i = 0; i < m; i++) {
        cin >> a[i] >> b[i];
        a[i]--, b[i]--;
    }

    vector<ll> cnt(m+1);
    cnt[m] = n*(n-1)/2;
    for (int i = m-1; i >= 0; i--) {
        
        if (uf.same(a[i], b[i])) {
            cnt[i] = cnt[i+1];
            continue;
        }
        cnt[i] = cnt[i+1] - (ll)uf.size(a[i])*(ll)uf.size(b[i]);
        uf.unite(a[i], b[i]);
    }

    for (int i = 1; i <= m; i++)
        cout << cnt[i] << endl;

    return 0;
}
