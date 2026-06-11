#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
template <class T>
using v = vector<T>;
template <class T>
using vv = v<v<T>>;
#define ALL(c) (c).begin(), (c).end()

vv<int> graph;
v<bool> seen;

void dfs(int v)
{
    seen[v] = true;

    for (auto next : graph[v])
    {
        if (seen[next])
            continue;

        dfs(next);
    }
}

int main()
{
    int N, M;
    cin >> N >> M;
    v<int> A(M), B(M);
    graph.assign(N, v<int>(M, 0));
    seen.assign(N, false);
    v<int> G(M, 0);

    for (int i = 0; i < M; i++)
    {
        cin >> A[i] >> B[i];
        A[i]--, B[i]--;
    }

    int ans = 0;

    for (int i = 0; i < M; i++)
    {
        graph.assign(N, v<int>());
        seen.assign(N, false);

        for (int j = 0; j < M; j++)
        {
            if (i != j)
            {
                graph[A[j]].push_back(B[j]);
                graph[B[j]].push_back(A[j]);
            }
        }

        dfs(0);

        bool check = false;
        for (int j = 0; j < N; j++)
        {
            if (!seen[j])
                check = true;
        }

        if (check)
            ans++;
    }

    cout << ans << endl;
    return 0;
}