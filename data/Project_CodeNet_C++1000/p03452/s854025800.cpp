#include <bits/stdc++.h>
using namespace std;

int n, m;
int chk[100001];
struct edg {
    int idx, dst;
};
vector<edg> gph[100001];
int dst[100001];

void go(int now, int cnt) {
    dst[now] = cnt;
    chk[now] = 1;
    for (edg nxt : gph[now]) {
        if (!chk[nxt.idx]) {
            go(nxt.idx, cnt+nxt.dst);
        }
        else {
            if (dst[nxt.idx] != cnt+nxt.dst) {
                puts("No");
                exit(0);
            }
        }
    }
}

int main() {
    scanf("%d %d", &n, &m);
    while (m--) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        gph[u].push_back({ v,w });
        gph[v].push_back({ u,-w });
    }

    for (int i = 1; i <= n; i++) {
        if (!chk[i]) {
            go(i, 0);
        }
    }

    puts("Yes");

    return 0;
}
