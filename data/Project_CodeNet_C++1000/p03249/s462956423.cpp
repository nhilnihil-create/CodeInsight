#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

typedef long long ll;
typedef pair <int, int> ii;

const int Maxn = 100005;

int n;
ll D[Maxn];
map <ll, ll> M;
map <ll, int> ind;
vector <ii> res;
vector <int> neigh[Maxn];
ll cor;

ll Solve(int v, int p, int cur)
{
    ll res = cur;
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i];
        if (p == u) continue;
        res += Solve(u, v, cur + 1);
    }
    return res;
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &D[i]);
        ind[D[i]] = i;
        M[D[i]] = 0;
    }
    sort(D, D + n);
    for (int i = n - 1; i > 0; i--) {
        ll my = M[D[i]] + 1;
        if (my >= n - my) { printf("-1\n"); return 0; }
        ll need = D[i] + 2ll * ll(my) - ll(n);
        map <ll, ll>::iterator it = M.find(need);
        if (it == M.end()) { printf("-1\n"); return 0; }
        it->second += my;
        int A = ind[D[i]], B = ind[need];
        neigh[A].push_back(B);
        neigh[B].push_back(A);
        res.push_back(ii(A, B));
    }
    if (M[D[0]] != n - 1) { printf("-1\n"); return 0; }
    if (Solve(ind[D[0]], -1, 0) != D[0]) { printf("-1\n"); return 0; }
    for (int i = 0; i < n - 1; i++)
        printf("%d %d\n", res[i].first + 1, res[i].second + 1);
    return 0;
}
