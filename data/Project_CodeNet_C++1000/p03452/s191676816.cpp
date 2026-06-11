#pragma region include
#include "bits/stdc++.h"
#define ALL(obj) (obj).begin(),(obj).end()
#define RALL(obj) (obj).rbegin(),(obj).rend()
#define REP(i, n) for(int i = 0; i < (int)(n); i++)
#define REPR(i, n) for(int i = (int)(n); i >= 0; i--)
#define FOR(i,n,m) for(int i = (int)(n); i < int(m); i++)
#define MOD (int)(1e9+7)
#define INF (int)(1e9)
#define LLINF (int)(4e18)
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<VI> VVI;
void input() {}
template<typename... R> void input(int& f, R&... r) { scanf("%d", &f); input(r...); }
template<typename... R> void input(double& f, R&... r) { scanf("%lf", &f); input(r...); }
template<typename... R> void input(ll& f, R&... r) { scanf("%lld", &f); input(r...); }
template<typename... R> void input(char& f, R&... r) { scanf("%c", &f); input(r...); }
template<typename T, typename... R> void input(vector<T>& f, R&... r) { REP(i, f.size())input(f[i]); input(r...); }
#pragma endregion

struct Edge {
    int to, cost;
};

vector<vector<Edge>> G;
vector<bool> visited;
vector<int> dist;

bool dfs(int v,int p=-1, int c=0) {
    visited[v] = true;
    dist[v] = c;
    for (Edge e : G[v]) {
        if (e.to == p) continue;
        if (visited[e.to]) {
            if (dist[e.to] != c + e.cost) {
                return false;
            }
        }
        else {
            if (!dfs(e.to,v,c + e.cost)) return false;
        }
    }
    return true;
}

int main() {
    int N,M; input(N,M);
    visited.resize(N, false);
    dist.resize(N);
    G.resize(N, vector<Edge>());
    REP(i,M) {
        int l, r, d; input(l,r,d);
        l--; r--;
        G[l].push_back({r,d});
        G[r].push_back({l,-d});
    }
    bool flag = false;
    REP(i, N) {
        if (visited[i]) continue;
        if (!dfs(i)) {
            flag = true;
            break;
        }
    }
    if (flag) {
        puts("No");
    }
    else {
        puts("Yes");
    }
    getchar(); getchar();
}