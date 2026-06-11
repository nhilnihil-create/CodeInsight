#include<bits/stdc++.h>
using namespace std;

void dfs(const vector<vector<int>> &G, int v, vector<bool> &seen) {
    seen[v] = true;
    for (auto next_v : G[v]) {
        if (seen[next_v]) continue;
        dfs(G, next_v, seen);
    }
}

int main(void)
{
    long long N, M;
    cin >> N >> M;
    vector<long long> a(M);
    vector<long long> b(M);
    for (long long i = 0; i < M; i++)
    {
        long long A, B;
        cin >> A >> B;
        a[i] = A - 1;
        b[i] = B - 1;
    }

    long long ans = 0;
    vector<vector<int>> G(N);
    vector<bool> seen(N);
    for (long long i = 0; i < M; i++)
    {
        G[a[i]].push_back(b[i]);
        G[b[i]].push_back(a[i]);
    }
    for (long long j = 0; j < M; j++)
    {
        for (long long i = 0; i < N; i++)
        {
            seen[i] = false;
        }
        G[a[j]].erase(remove(G[a[j]].begin(), G[a[j]].end(), b[j]), G[a[j]].end());
        G[b[j]].erase(remove(G[b[j]].begin(), G[b[j]].end(), a[j]), G[b[j]].end());
        dfs(G, 1, seen);
        G[a[j]].push_back(b[j]);
        G[b[j]].push_back(a[j]);
        for (long long i = 0; i < N; i++)
        {
            if (seen[i] == false)
            {
                ans++;
                break;
            }
        }
    }
    cout << ans << endl;
}