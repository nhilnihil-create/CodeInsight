#include <bits/stdc++.h>
using namespace std;
int n;
long long d[100001];
int x[100001];
int size[100001];
long long g[100001];
vector<pair<int, int> > edge;
map<long long, int>f;
bool cmp(int x, int y) {
    return d[x] > d[y];
}
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n ; i ++)
        scanf("%lld", &d[i]), x[i] = i, size[i] = 1, f[d[i]] = i;
    sort(x + 1, x + n + 1, cmp);
    bool sig = 0;
    for (int i = 1; i <= n ; i ++) {
        long long dd = d[x[i]] +size[x[i]] - n + size[x[i]];
        if (dd != d[x[i]]&&f[dd] && dd < d[x[i]]) size[f[dd]] += size[x[i]], edge.push_back(make_pair(x[i], f[dd])), g[f[dd]] += g[x[i]] + size[x[i]];
    }
    if (size[x[n]] == n && edge.size() == n - 1 &&g[x[n]] == d[x[n]]){
        for (auto u : edge) printf("%d %d\n", u.first, u.second);
    } else printf("-1");
    return 0;
}