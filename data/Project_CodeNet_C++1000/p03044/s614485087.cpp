#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e9+7;
int mod = 1234567;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
signed main() {
    int N;
    cin >> N;
    vector<vector<P>>ki(N);
    for(int i = 0; i < N-1; i++) {
        int u,v,w;
        cin >> u >> v >> w;
        u--;v--;
        ki[u].push_back({v,w});
        ki[v].push_back({u,w});
    }
    vector<int>cnt(N,INF);
    cnt[0] = 0;
    queue<P>que;
    que.push({0,0});
    while(!que.empty()) {
        P x = que.front();
        que.pop();
        for(int i = 0; i < ki[x.first].size(); i++) {
            if(cnt[ki[x.first][i].first] == INF) {
                cnt[ki[x.first][i].first] = x.second+ki[x.first][i].second;
                que.push({ki[x.first][i].first,cnt[ki[x.first][i].first]});
            }
        }
    }
    for(int i = 0; i < N; i++) {
        if(cnt[i]%2 == 0) {
            cout << 0 << endl;
        }
        else {
            cout << 1 << endl;
        }
    }
}
