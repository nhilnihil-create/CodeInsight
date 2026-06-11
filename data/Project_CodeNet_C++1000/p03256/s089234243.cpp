#include <algorithm>
#include <cstdio>
#include <cstring>

const int Maxv = 200010; 

int Head[Maxv], cnt; 

struct Node {
    int v, next; 
} N[Maxv << 1]; 

inline void addEdge(int u, int v) {
    N[++cnt].v = v; 
    N[cnt].next = Head[u]; 
    Head[u] = cnt; 
}

int deg[Maxv][2], q[Maxv], head, tail, n, m; 
char col[Maxv]; 
bool vis[Maxv]; 

int main() {
    scanf("%d%d", &n, &m); 
    scanf("%s", col + 1); 

    for (int i = 1; i <= m; i++) {
        int u, v; 
        scanf("%d%d", &u, &v); 
        addEdge(u, v); 
        addEdge(v, u); 
        deg[u][col[v] == 'B']++; 
        deg[v][col[u] == 'B']++; 
    }

    for (int i = 1; i <= n; i++) {
        if (deg[i][0] == 0 || deg[i][1] == 0) {
            vis[q[tail++] = i] = true; 
        }
    }
    
    while (head != tail) {
        int x = q[head++]; 

        for (int i = Head[x]; i; i = N[i].next) {
            if (!vis[ N[i].v ]) {
                if (--deg[ N[i].v ][col[x] == 'B'] == 0) {
                    vis[ N[i].v ] = true; 
                    q[tail++] = N[i].v; 
                }
            }
        }
    }

    if (tail == n) puts("No"); 
    else puts("Yes"); 

    return 0; 
}