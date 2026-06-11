#include <bits/stdc++.h>

#include <algorithm>
using namespace std;
struct Fast {
    Fast() {
        cin.tie(0);
        ios::sync_with_stdio(false);
        cout << fixed << setprecision(20);
    }
} fast;

long long mod = 1000000007;

long long modpow(long long m, long long n) {
    if (n == 0) return 1;
    if (n % 2 == 0) {
        long long t = modpow(m, n / 2);
        return (t * t) % mod;
    } else {
        return (modpow(m, n - 1) * m) % mod;
    }
}

void yes() {
    cout << "Yes" << endl;
    exit(0);
}
void no() {
    cout << "No" << endl;
    exit(0);
}
#define REP(i, n) for (long long i = 0; i < (n); i++)

struct UnionFind {
    vector<int> parent, size;

    UnionFind(int n) {
        parent.resize(n, -1);
        size.resize(n, 1);
    }
    void unite(int x, int y) {
        x = root(x);
        y = root(y);
        if (size[x] <= size[y]) {
            swap(x, y);
        }
        parent[y] = x;
        size[x] += size[y];
    }
    bool same(int x, int y) { return (root(x) == root(y)); }
    int root(int x) {
        while (parent[x] != -1) {
            x = parent[x];
        }
        return x;
    }
    int getsize(int x) { return size[root(x)]; }
};

signed main() {
    long long n, m, ans = 0;
    cin >> n >> m;
    vector<long long> as(m);
    vector<long long> bs(m);
    vector<long long> ansv(m);
    ans = n * (n - 1) / 2;
    REP(i, m) {
        cin >> as[i] >> bs[i];
        as[i] -= 1;
        bs[i] -= 1;
    }
    reverse(as.begin(), as.end());
    reverse(bs.begin(), bs.end());
    UnionFind uf(n);
    ansv[0] = ans;
    REP(i, m - 1) {
        if (!uf.same(as[i], bs[i])) {
            ans -= uf.getsize(bs[i]) * uf.getsize(as[i]);
            uf.unite(as[i], bs[i]);
            ansv[i + 1] = ans;
        } else {
            ansv[i + 1] = ansv[i];
        }
    }
    reverse(ansv.begin(), ansv.end());
    REP(i, m) { cout << ansv[i] << endl; }
}