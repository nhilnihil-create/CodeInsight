#include <bits/stdc++.h>

#define ln                '\n'
#define all(dat)           dat.begin(), dat.end()
#define loop(i, to)        for (int i = 0; i < to; ++i)
#define cont(i, to)        for (int i = 1; i <= to; ++i)
#define circ(i, fr, to)    for (int i = fr; i <= to; ++i)
#define foreach(i, dat)    for (__typeof(dat.begin()) i = dat.begin(); i != dat.end(); ++i)

typedef long long          num;

using namespace std;

const int nsz = 1e5;
int n, rt, siz[nsz + 5];
num w[nsz + 5];
map<num, int> id, to;
vector<int> g[nsz + 5];
vector<pair<int, int>> ans;

num inline cmp(num a, num b) {
    return a > b;
}

num calc(int u = rt, int dep = 0) {
    num res = dep;
    for (int v : g[u]) {
        res += calc(v, dep + 1);
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n;
    rt = n;
    cont (i, n) {
        cin >> w[i];
        to[w[i]] = i;
    }
    fill(siz, siz + sizeof(siz) / sizeof(int), 1);
    sort(w + 1, w + n + 1, cmp);
    cont (i, n) {
        id[w[i]] = i;
    }
    cout << ln;
    cont (u, n) {
        if (u == rt)  continue;
        int v = id[w[u] - n + 2 * siz[u]];
        if (!v) {
            cout << -1 << ln;
            return 0;
        }
        siz[v] += siz[u];
        g[v].push_back(u);
        ans.push_back({to[w[u]], to[w[v]]});
    }
    if (calc() != w[n]) {
        cout << -1 << ln;
        return 0;
    }
    for (pair<int, int> p : ans) {
        cout << p.first << ' ' << p.second << ln;
    }
}
