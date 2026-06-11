#include <bits/stdc++.h>
using namespace std;

const int NMAX = 1e5 + 5;
int n;
long long dp[NMAX];
bool vis[NMAX];
queue<int> q;
vector<pair<int, int>> graf[NMAX];

int main() {
    
    cin >> n;
    for(int i = 1; i < n; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        graf[x].push_back({y, w});
        graf[y].push_back({x, w});
    }
    q.push(1);
    while(!q.empty()) {
        int nod = q.front();
        vis[nod] = 1;
        q.pop();
        for(int i = 0; i < (int)graf[nod].size(); i++) {
            int next = graf[nod][i].first;
            int cost = graf[nod][i].second;
            if(!vis[next]) {
                dp[next] = dp[nod] + cost;
                q.push(next);
            }
        }
    }
    for(int i = 1; i <= n; i++) {
        cout << dp[i] % 2 << '\n';
    }
    return 0;
}