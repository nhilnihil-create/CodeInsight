#include <bits/stdc++.h>

#define N 300010 

using namespace std;

int head[N], to[N << 1], nxt[N << 1], tot;

int dep[N], sz[N];

typedef long long ll;

struct Node {
    ll num;
    int id;
}a[N];

inline bool cmp(const Node &a, const Node &b) {
    return a.num > b.num;
}

char *p1, *p2, buf[100000];

#define nc() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 100000, stdin), p1 == p2) ? EOF : *p1 ++ )

ll rd() {
    ll x = 0;
    char c = nc();
    while (c < 48) {
        c = nc();
    }
    while (c > 47) {
        x = (((x << 2) + x) << 1) + (c ^ 48), c = nc();
    }
    return x;
}

inline void add(int x, int y) {
    to[ ++ tot] = y;
    nxt[tot] = head[x];
    head[x] = tot;
}

void dfs(int p, int fa) {
    dep[p] = dep[fa] + 1;
    for(int i = head[p]; i; i = nxt[i]) {
        if (to[i] != fa) {
            dfs(to[i], p);
        }
    }
}

map <ll, int> MP;

map <ll, int> :: iterator it;

int u[N], v[N];

int main() {
    int n = rd();
    for (int i = 1; i <= n; i ++ ) {
        a[i].num = rd();
        MP[a[i].num] = i;
        a[i].id = i;
    }
    sort(a + 1, a + n + 1, cmp);

    for (int i = 1; i < n; i ++ ) {
        int x = a[i].id;
        it = MP.find(a[i].num - n + 2 + (sz[x] << 1));
        if (it == MP.end()) {
            puts("-1");
            return 0;
        }
        int y = it -> second;
        sz[y] += sz[x] + 1;
        add(x, y);
        add(y, x);
        u[i] = x;
        v[i] = y;
    }
    // puts("Fuck");
    dep[a[n].id] = -1;
    dfs(a[n].id, a[n].id);
    ll all = 0;
    for (int i = 1; i <= n; i ++ ) {
        all += dep[i];
    }
    if (all != a[n].num) {
        puts("-1");
        return 0;
    }
    for (int i = 1; i < n; i ++ ) {
        printf("%d %d\n", u[i], v[i]);
    }
    return 0;
}