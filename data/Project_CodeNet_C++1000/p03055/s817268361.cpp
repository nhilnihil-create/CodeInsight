#include <bits/stdc++.h>

const int N = 200010;

struct Edge {
    int nex, v;
}edge[N << 1]; int tp;

int n, e[N], sg[N], f[N], Ans;

inline void add(int x, int y) {
    edge[++tp].v = y;
    edge[tp].nex = e[x];
    e[x] = tp;
    return;
}

void DFS(int x, int fa) {
    int a = 1, b = 0;
    for(int i = e[x]; i; i = edge[i].nex) {
        int y = edge[i].v;
        if(y == fa) continue;
        DFS(y, x);
        if(a < f[y] + 1) {
            b = a;
            a = f[y] + 1;
        }
        else {
            b = std::max(b, f[y] + 1);
        }
    }
    Ans = std::max(Ans, std::max(a + b - 1, a));
    f[x] = a;
    return;
}

int main() {

    int n;
    scanf("%d", &n);
    for(int i = 1, x, y; i < n; i++) {
        scanf("%d%d", &x, &y);
        add(x, y);
        add(y, x);
    }

    DFS(1, 0);

    /// cal Ans
    sg[1] = 1;
    sg[2] = 0;
    for(int i = 3; i <= Ans; i++) {
        if(std::min(sg[i - 1], sg[i - 2]) == 0) {
            sg[i] = 1;
        }
        else {
            sg[i] = 0;
        }
    }

    if(sg[Ans]) {
        printf("First\n");
    }
    else {
        printf("Second\n");
    }

    return 0;
}
