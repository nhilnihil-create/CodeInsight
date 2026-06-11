#include <bits/stdc++.h>
#define REP(i, a) for(int i=0; i<int(a); i++)
#define ALL(x) begin(x), end(x)
#define VI vector<int>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int MAX_N=100005;
const int INF = 1e9;
vector<PII> edges[MAX_N];
LL dist[MAX_N];

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    REP(i, m) {
        int a, b, w;
        scanf("%d %d %d", &a, &b, &w);
        edges[a].push_back({b, w});
        edges[b].push_back({a, -w});
    }

    REP(i, n+1) dist[i] = INF;
    for(int i=1; i<=n; i++) {
        if(dist[i] == INF) {
            queue<int> q;
            q.push(i);
            dist[i] = 0;
            while(q.size()) {
                int from = q.front();
                q.pop();
                for(auto p:edges[from]) {
                    int to = p.first;
                    LL cost = p.second;
                    if(dist[to] == INF) {
                        dist[to] = dist[from] + cost;
                        q.push(to);
                    } else if(dist[to] != dist[from] + cost) {
                        cout << "No" << endl;
                        return 0;
                    }
                }
            }
        }
    }
    cout << "Yes" << endl;
    return 0; 
}

