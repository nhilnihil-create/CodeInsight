#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

typedef long long ll;
typedef pair<ll, int> P;
const int INFTY = 1001001001;

void bfs(vector<vector<int>> &edges, vector<P> &dist, int node)
{
    queue<int> Q;
    Q.push(node);
    dist[node].first = 0;
    while (!Q.empty())
    {
        node = Q.front();
        Q.pop();
        for (int e : edges[node])
        {
            if (dist[e].first == INFTY)
            {
                dist[e].first = dist[node].first + 1;
                Q.push(e);
            }
        }
    }
}

int main()
{
    int N;
    cin >> N;
    vector<vector<int>> edges(N);
    vector<P> dist(N), e(N-1);
    vector<int> cost(N);

    int a, b;
    for (int i = 0; i < N - 1; ++i)
    {
        cin >> a >> b;
        edges[--a].push_back(--b);
        edges[b].push_back(a);
        e[i] = P(a, b);
    }

    int max_index, max_v = -1;
    for (int i = 0; i < N; ++i)
    {
        cin >> cost[i];
        dist[i].second = i;
        dist[i].first = INFTY;
        if ((int)edges[i].size() > max_v)
        {
            max_v = edges[i].size();
            max_index = i;
        }
    }

    bfs(edges, dist, max_index);
    sort(dist.begin(), dist.end(), less<P>());
    sort(cost.begin(), cost.end(), greater<int>());

    vector<int> nodes(N);
    for (int i = 0; i < N; ++i)
    {
        nodes[dist[i].second] = cost[i];
    }

    int ans = 0;
    for(P p : e){
        //cout << p.first << " " << p.second << " " << nodes[p.first] << " " << nodes[p.second] << endl;
        ans += min(nodes[p.first], nodes[p.second]);
    }

    cout << ans << endl;
    for (int i = 0; i < N; ++i)
    {
        if (i)
            cout << " ";
        cout << nodes[i];
    }
    cout << endl;
}
