#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

vector<ll> distances;
vector<vector<pll>> edges;
ll INF = 1e16;

bool dfs(int node)
{
    for (auto edge : edges.at(node))
    {
        ll nextNode, distance;
        tie(nextNode, distance) = edge;
        if (distances.at(nextNode) != INF && distances.at(nextNode) - distances.at(node) != distance)
        {
            return false;
        }
        if (distances.at(nextNode) == INF)
        {
            distances.at(nextNode) = distances.at(node) + distance;
            if (!dfs(nextNode))
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, M;
    cin >> N >> M;
    edges = vector<vector<pll>>(N + 1, vector<pll>());
    for (int i = 0; i < M; i++)
    {
        ll L, R, D;
        cin >> L >> R >> D;
        edges.at(L).emplace_back(R, D);
        edges.at(R).emplace_back(L, D * -1);
    }
    distances = vector<ll>(N + 1, INF);
    string answer = "Yes";
    for (int i = 1; i <= N; i++)
    {
        if (distances.at(i) == INF)
        {
            distances.at(i) = 0;
            if (!dfs(i))
            {
                answer = "No";
                break;
            }
        }
    }
    cout << answer << endl;
    return 0;
}
