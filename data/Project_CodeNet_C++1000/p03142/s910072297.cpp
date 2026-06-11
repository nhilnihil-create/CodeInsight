#include <bits/stdc++.h>

using namespace std;

const unsigned long long MOD = 1000000007LL;
long long GCD(long long a, long long b){return b == 0 ? a : GCD(b, a % b);}
long long fast_exp(long long base, long long exp) {
    long long tot = 1;
    for(;exp > 0;exp >>= 1) {
       if((exp & 1) == 1) tot = tot * base % MOD;
       base = base * base % MOD;
    }
    return tot;
}

int deg[100001], dist[100001];
pair<int, int> parent[100001];
vector<int> adj[100001];

int main(){

    cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    // if the original tree is uniquely determined, then there must be one node that has an indegree of 0

    // proof: suppose that X is the original root. if we add a new edge from Y to X, then it is possible that Y was the root, and it becomes ambiguous

    // now, we have to find the right edges to pair up with the nodes

    // each of the new M edges will shorten some path between two nodes
    // therefore it should work if we pair up a child node to the node that is furthest from the root

    int n, m; cin >> n >> m;

    for(int i = 0; i < n - 1 + m; ++i){
        int a, b; cin >> a >> b;
        --a; --b;
        adj[a].push_back(b);
        ++deg[b];
    }

    queue<int> q;

    for(int i = 0; i < n; ++i){
        dist[i] = -1;
        parent[i] = make_pair(-1, -1);
        if(deg[i] != 0) continue;
        q.push(i);
        dist[i] = 0;
        parent[i] = make_pair(0, 0);
    }

    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(auto nx : adj[node]){
            dist[nx] = max(dist[nx], dist[node] + 1);
            if(--deg[nx] == 0)
                q.push(nx);
        }
    }

    for(int i = 0; i < n; ++i)
        for(int j : adj[i])
            parent[j] = max(parent[j], make_pair(dist[i], i + 1));

    for(int i = 0; i < n; ++i)
        cout << parent[i].second << "\n";

    return 0;

}
