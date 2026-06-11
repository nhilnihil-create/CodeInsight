#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
typedef long long ll;
int n, m, fa[N];
ll dis[N];

int getfa(int w) {
    if (fa[w] == w) return w;
    int tmp = fa[w];
    fa[w] = getfa(fa[w]);
    dis[w] += dis[tmp];
    return fa[w];
}

int get_dis(int w) {
    return fa[w] == w ? 0 : get_dis(fa[w]) + dis[w];
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i <= n; i++) fa[i] = i;
    for (int i = 1; i <= m; i++) {
        int L, R, D;
        scanf("%d%d%d", &L, &R, &D);
        int fl = getfa(L), fr = getfa(R);
        if (fl == fr) {
            if (dis[L] + D != dis[R]) {
                puts("No"); return 0;
            }
        } else {
            fa[fr] = fl;
            dis[fr] = get_dis(L) - get_dis(R) + D;
        }
    }
    puts("Yes");
    return 0;
}
