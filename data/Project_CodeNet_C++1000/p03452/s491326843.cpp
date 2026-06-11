#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
#define INF 1007654321
#define PI 3.14159265358979
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define repp(i, s, e) for(int i = (s); i <= (e); ++i)
#define sz(x) ((int)x.size())
#define all(x) x.begin(), x.end()
#define FAST_IO() ios::sync_with_stdio(0); cin.tie(0)
template<typename T>
ostream& operator<<(ostream &os, const vector<T> &v) { for (auto x : v) os << x << " "; return os << "\n"; }

int main() {
    FAST_IO();
    int N, M; cin >> N >> M;
    vector<vector<pii>> adj(N);
    vector<int> indegree(N), outdegree(N);
    rep(i, M) {
        int L, R, D; cin >> L >> R >> D;
        adj[R-1].push_back({L-1, D});
        indegree[L-1]++;
        outdegree[R-1]++;
    }
    vector<int> dist(N, -1);
    rep(i, N) if(outdegree[i] == 0) dist[i] = 1e9;
    // Topology sort
    queue<int> Q;
    rep(i, N) if(indegree[i] == 0) {
        Q.push(i);
    }
    vector<int> sorted;
    rep(i, N) {
        if(Q.empty()) { // if exist cycle
            cout << "No\n";
            return 0;
        }
        int here = Q.front(); Q.pop();
        sorted.push_back(here);
        for(auto &e : adj[here]){
            int next = e.first;
            if(--indegree[next] == 0) {
                Q.push(next);
            }
        }
    }
    bool ans = true;
    rep(i, N) {
        int curr = sorted[N - 1 - i];
        if(dist[curr] != -1) continue;
        int minX = 1e9, maxX = 0;
        for(auto &e : adj[curr]) {
            int next = e.first, d = e.second;
            minX = min(minX, dist[next] - d);
            maxX = max(maxX, dist[next] - d);
        }
        if(minX == maxX) dist[curr] = minX;
        else {
            ans = false;
            break;
        }
    }
    if(ans) cout << "Yes\n";
    else cout << "No\n";
    return 0;
}