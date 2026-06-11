#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<map>
#include<vector>

typedef long long ll;

int const N = 1e5 + 5;

int fa[N];
int sz[N];
ll a[N];
ll dis[N];
bool vis[N];
int n;

std::vector<int> E[N];
void addedge2(int x, int y) {
    E[x].push_back(y);
    E[y].push_back(x);
}

void dfs(int x, ll& sum, int dep) {
    sz[x] = 1;
    vis[x] = 1;
    sum += dep;
    for(auto y : E[x]) if(vis[y] == 0) {
        dfs(y, sum, dep + 1);
        sz[x] += sz[y];
    }
}

bool chk(int x, ll ans) {
    if(a[x] != ans) return 0;
    vis[x] = 1;
    bool ret = 1;
    for(auto& y : E[x]) if(vis[y] == 0) {
        ret &= chk(y, ans + n - 2ll * sz[y]);
    }
    return ret;
}

int main() {
    std::map<ll, int, std::greater<ll> > M;
    std::ios::sync_with_stdio(0);
    std::cin >> n;
    for(int i = 1; i <= n; ++i) {
        std::cin >> a[i];
        M.insert(std::make_pair(a[i], i));
    }
    for(auto& k : M) if(k.first != (*M.rbegin()).first) {
        int now = k.second;
        ++sz[now];
        ll f = k.first + 2ll * sz[now] - n;
        if(M.count(f) == 0) {
            puts("-1");
            return 0;
        }
        fa[now] = M[f];
        sz[fa[now]] += sz[now];
        ::addedge2(now, fa[now]);
    }
    int root = (*M.rbegin()).second;
    ll ans_root = 0;
    memset(vis, 0, sizeof(vis));
    memset(sz, 0, sizeof(sz));
    dfs(root, ans_root, 0);
    memset(vis, 0, sizeof(vis));
    if(chk(root, ans_root) == 0) {
        puts("-1");
        return 0;
    }
    for(int i = 1; i <= n; ++i) if(fa[i] != 0) {
        std::cout << fa[i] << ' ' << i << '\n';
    }
    return 0;
}