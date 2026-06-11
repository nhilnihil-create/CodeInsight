#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize(4)
#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pi acos(-1.0)
#define LL long long
//#define mp make_pair
#define pb push_back
#define ls rt<<1, l, m
#define rs rt<<1|1, m+1, r
#define ULL unsigned LL
#define pll pair<LL, LL>
#define pii pair<int, int>
#define piii pair<pii, int>
#define mem(a, b) memset(a, b, sizeof(a))
#define fio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define fopen freopen("in.txt", "r", stdin);freopen("out.txt", "w", stout);
//head

const int N = 2e5 + 10;
vector<int> g[N];
char s[N];
bool vis[N];
int d[N][2];
int que[N], top = 0;
int main() {
    int n, m, u, v;
    scanf("%d %d", &n, &m);
    scanf("%s", s);
    for (int i = 1; i <= m; i++) {
        scanf("%d %d", &u, &v);
        g[u].pb(v);
        g[v].pb(u);
    }
    for (int i = 1; i <= n; i++) {
        for (int v : g[i]) {
            d[v][s[i-1] - 'A']++;
        }
    }
    for (int i = 1; i <= n; i++) {
        if(!d[i][0] || !d[i][1]) que[++top] = i, vis[i] = true;
    }
    int now = 1;
    while(now <= top) {
        int u = que[now];
        for (int v : g[u]) {
            d[v][s[u-1] - 'A'] --;
            if(!vis[v] && !d[v][s[u-1] - 'A']) que[++top] = v, vis[v] = true;
        }
        now++;
    }
    if(top < n) puts("Yes");
    else puts("No");
    return 0;
}
