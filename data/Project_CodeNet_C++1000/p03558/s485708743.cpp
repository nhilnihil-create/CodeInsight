#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>

#define int long long
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define REPS(i,n) for(int i=1, i##_len=(n); i<=i##_len; ++i)

#define INF (1e9)

using namespace std;

int K;

struct Edge
{
    int to, cost;
};

typedef pair<int, int> P;

int dist[100001];
vector<Edge> ve[100001];

signed main()
{
    cin >> K;

    REP(i, K)
    {
        Edge e1;
        e1.to = (i+1) % K;
        e1.cost = 1;
        ve[i].push_back(e1);

        Edge e2;
        e2.to = (i*10) % K;
        e2.cost = 0;
        ve[i].push_back(e2);
    }

    REP(i, K) dist[i] = INF;
    dist[1] = 1;

    deque<P> d;
    d.push_front(P(1,0));
    while (!d.empty())
    {
        P p = d.front();
        d.pop_front();
        int v = p.first;
        if (dist[v] < p.second) continue;
        REP(i, ve[v].size())
        {
            Edge& e = ve[v][i];
            if (dist[e.to] > dist[v] + e.cost)
            {
                dist[e.to] = dist[v] + e.cost;
                if (e.cost == 1) d.push_back(P(e.to, dist[e.to]));
                if (e.cost == 0) d.push_front(P(e.to, dist[e.to]));
            }
        }
    }

    cout << dist[0] << endl;

    return 0;
}