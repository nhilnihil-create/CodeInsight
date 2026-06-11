#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5 + 5;
bool flag[maxn];
struct
{
    int v, next;
}e[maxn<<1];

int dep[maxn];
int h[maxn], mem;
void pre()
{
    flag[1] = 1;
    flag[2] = 0;
    flag[3] = 1;
    memset(h, -1, sizeof(h));
    mem = 0;
    for(int i=4; i<maxn; i++)
    {
        if(flag[i-1]&flag[i-2]) flag[i] = 0;
        else flag[i] = 1;
    }
}

void add(int u, int v)
{
    e[mem].v = v;
    e[mem].next = h[u];
    h[u] = mem++;
    e[mem].v = u;
    e[mem].next = h[v];
    h[v] = mem++;
}

void dfs(int u, int fa)
{
    dep[u] = dep[fa] + 1;
    for(int i=h[u]; i+1; i=e[i].next)
    {
        int v = e[i].v;
        if(v==fa) continue;
        dfs(v, u);
    }

}


int main()
{
    pre();
    int n;
    scanf("%d", &n);
    for(int i=1; i<n; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        add(x, y);
    }
    memset(dep, 0, sizeof(dep));
    dfs(1, 1);
    int maxdep=0, id=0;
    for(int i=1; i<=n; i++)
    {
        if(dep[i] > maxdep){
            maxdep = dep[i];
            id = i;
        }
    }

    memset(dep, 0, sizeof(dep));
    dfs(id, id);
    maxdep = 0;
    for(int i=1; i<=n; i++)
    {
        if(dep[i] > maxdep){
            maxdep = dep[i];
            id = i;
        }
    }

    printf("%s\n", flag[maxdep]?"First":"Second");

    return 0;
}






















