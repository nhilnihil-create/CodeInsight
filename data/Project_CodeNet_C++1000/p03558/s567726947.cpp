#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define rep(i, n) FOR(i, 0, n)
#define rrep(i, n) for (int i = ((int)(n)-1); i >= 0; --i)
#define whole(x) (x).begin(),(x).end()
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end())
using P = pair<int, int>;
#define debug(var) cerr << "[" << #var << "] " << var << endl
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)
const ll mod = 1000000007;
const int dx[] = {-1,0,1,0};
const int dy[] = {0,-1,0,1};
const int INF = 1001001001;

vector<P> to[100005];
int dist[100005];

int main(){
    int k;
    cin >> k;
    for (int i=1; i<=k-1; i++) {
        to[i].emplace_back(i+1, 1);
    }
    for (int i=1; i<=k-1; i++) {
        int j = (i*10-1)%k+1;
        to[i].emplace_back(j, 0);
    }
    for (int i=1; i<=k; i++) {
        dist[i] = INF;
    }
    auto comp = [](P a, P b) {
        return a.second>b.second;
    };
    priority_queue<P, vector<P>, decltype(comp)> q{comp};
    q.emplace(1, 1);
    dist[1] = 1;
    while (!q.empty()) {
        P now = q.top();
        q.pop();
        int x = now.first;
        int d = now.second;
        for (auto e: to[x]) {
            int dd = d + e.second;
            if (dist[e.first]<=dd) continue;
            dist[e.first] = dd;
            q.emplace(e.first, dd);
        }
    }
    
    int ans = dist[k];
    
    cout << ans << endl;
    return 0;
}
