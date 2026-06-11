#include <bits/stdc++.h>
using namespace std;

#define LL long long
const int N = 2e5;
int n, cnt;
int fa[N], ff[N];
LL di[N], siz[N];
map <LL, int> val;
pair <int, int> edges[N];
int ord[N];
int get_f(int t)
{
    if (ff[t] == t) return t;
    else return ff[t] = get_f(ff[t]);
}
vector <int> bi[N];
int tss[N];
LL sum[N];
void dfs1(int t, int f = 0)
{
    tss[t] = 1;
    for (int i = 0; i < bi[t].size(); ++ i)
        if (bi[t][i] != f)
        {
            dfs1(bi[t][i], t);
            sum[t] += sum[bi[t][i]] + tss[bi[t][i]];
            tss[t] += tss[bi[t][i]];
        }
}
void dfs2(int t, int f = 0, LL u = sum[1])
{
    if (u != di[t]) {puts("-1"); exit(0);}
    for (int i = 0; i < bi[t].size(); ++ i)
        if (bi[t][i] != f)
            dfs2(bi[t][i], t, u + n - 2 * tss[bi[t][i]]);
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++ i) scanf("%lld", &di[i]);
    for (int i = 1; i <= n; ++ i) ord[i] = i, val[di[i]] = i, ff[i] = i;
    sort(ord + 1, ord + n + 1, [=](int a, int b) {return di[a] > di[b];});
    for (int i = 1; i < n; ++ i)
    {
        int p = ord[i];
        siz[p] += 1;
        LL q = di[p] + siz[p] * 2 - n;
        if (!val.count(q)) {puts("-1"); return 0;}
        fa[p] = val[q];
        if (get_f(p) == get_f(fa[p])) {puts("-1"); return 0;}
        ff[get_f(p)] = get_f(fa[p]);
        siz[fa[p]] += siz[p];
        bi[p].push_back(fa[p]);
        bi[fa[p]].push_back(p);
        edges[i] = make_pair(p, fa[p]);
    }
    dfs1(1);
    dfs2(1);
    for (int i = 1; i < n; ++ i) printf("%d %d\n", edges[i].first, edges[i].second);
}
