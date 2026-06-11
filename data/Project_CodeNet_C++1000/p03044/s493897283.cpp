#include <bits/stdc++.h>
typedef long long int ll;

using namespace std;

int dfs(int u, vector<vector<int>>& G, vector<vector<int>>& G_w, vector<int> &visit, vector<int> &nagasa)
{

    visit[u] = 1;
    for (int i = 0; i < G[u].size(); i++)
    {

        int v = G[u][i];

        if (visit[v] == 0)
        {

            nagasa[v] = (nagasa[u] + G_w[u][i] % 2) % 2;
            dfs(v, G, G_w, visit, nagasa);
        }
    }

    return 0;
}

int main()
{

    int N;
    cin >> N;
    vector<vector<int>> G(N);

    vector<vector<int>> G_w(N);

    vector<int> nagasa(N, 0);
    vector<int> visit(N, 0);

    for (int i = 0; i < N - 1; i++)
    {

        int u, v, w;

        cin >> u >> v >> w;

        G[u - 1].push_back(v - 1);
        G[v - 1].push_back(u - 1);
        G_w[u - 1].push_back(w);
        G_w[v - 1].push_back(w);
    }

    dfs(0, G, G_w, visit, nagasa);

    for (int i = 0; i < N; i++)
    {

        if (nagasa[i] == 0)
        {

            cout << '1' << endl;
        }
        else
        {

            cout << '0' << endl;
        }
    }

    return 0;
}