#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > G;
vector<long long> b, w;
typedef long long ll;
ll mod = 1e9+7;

ll dfs_b(int s, int p);

ll dfs_w(int s, int p) {
    if (w[s] != -1)
        return w[s];
    ll cnt = 1;
    for (auto u: G[s]) {
        if (u == p)
            continue;
        
        ll tmp = dfs_w(u, s) + dfs_b(u, s);
        tmp %= mod;
        cnt *= tmp;
        cnt %= mod;
    }

    return w[s] = cnt;
}

ll dfs_b(int s, int p) {
    if (b[s] != -1)
        return b[s];
    ll cnt = 1;
    for (auto u: G[s]) {
        if (u == p)
            continue;
        
        cnt *= dfs_w(u, s);
        cnt %= mod;
    }

    return b[s] = cnt;
}

int main() {
    int n;  cin >> n;
    G.resize(n);
    w.resize(n, -1);
    b.resize(n, -1);

    for (int i = 0; i < n-1; i++) {
        int x, y;   cin >> x >> y;
        G[x-1].push_back(y-1);
        G[y-1].push_back(x-1);
    }

    cout << (dfs_w(0, -1) + dfs_b(0, -1)) % mod << endl;
    
    return 0;
}