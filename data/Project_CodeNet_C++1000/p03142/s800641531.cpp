/*
    Take me to church
    I'll worship like a dog at the shrine of your lies
    I'll tell you my sins and you can sharpen your knife
    Offer me that deathless death
    Good God, let me give you my life
*/
#include<bits/stdc++.h>
using namespace std;
const int N = 100005;
int n, m, R[N], M[N];
vector < int > T, Adj[N], Adt[N];
void DFS(int v)
{
    M[v] = 1;
    for (int u : Adj[v])
        if (!M[u]) DFS(u);
    T.push_back(v);
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n - 1 + m; i ++)
    {
        int v, u;
        scanf("%d%d", &v, &u);
        Adj[v].push_back(u);
        Adt[u].push_back(v);
    }
    for (int i = 1; i <= n; i ++)
        if (!M[i]) DFS(i);
    reverse(T.begin(), T.end());
    for (int i = 0; i < n; i ++)
        R[T[i]] = i;
    for (int i = 1; i <= n; i ++)
    {
        int id = i;
        for (int u : Adt[i])
            if (id == i || R[u] > R[id])
                id = u;
        if (id == i)
            id = 0;
        printf("%d\n", id);
    }
    return 0;
}