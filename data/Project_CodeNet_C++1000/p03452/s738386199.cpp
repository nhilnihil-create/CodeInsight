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
int n, m, Mn, A[N], M[N];
vector < pair < int , int > > Adj[N];
void DFS(int v, int tp)
{
    M[v] = tp;
    Mn = min(Mn, A[v]);
    for (auto u : Adj[v])
        if (M[u.first] != tp)
            A[u.first] = A[v] + u.second, DFS(u.first, tp);
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i ++)
    {
        int v, u, d;
        scanf("%d%d%d", &v, &u, &d);
        Adj[v].push_back({u, d});
        Adj[u].push_back({v, - d});
    }
    for (int i = 1; i <= n; i ++)
        if (!M[i])
        {
            A[i] = Mn = 0;
            DFS(i, 1);
            if (Mn < 0)
                A[i] = - Mn, DFS(i, 2);
        }
    for (int i = 1; i <= n; i ++)
        if (A[i] < 0 || A[i] > (int)(1e9))
            return !printf("No\n");
    for (int i = 1; i <= n; i ++)
        for (auto u : Adj[i])
            if (A[i] + u.second != A[u.first])
                return !printf("No\n");
    return !printf("Yes\n");
}