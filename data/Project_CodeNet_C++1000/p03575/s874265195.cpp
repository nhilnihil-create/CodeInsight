#include <algorithm>
#include <iostream>
#include <map>
#include <tuple>
#include <vector>
#include <deque>

#define rep(i, n) for (int i = 0; (i) < (n); (i)++)
using namespace std;
using ll = long long;
int G[50][50];

int main(void) {
    int N, M;
    cin >> N >> M;
    rep(i, N)
        rep(j, N)
            G[i][j] = -1;
    
    vector<pair<int, int>> B;
    rep(i, M) {
        int a, b;
        cin >> a >> b;
        G[a-1][b-1] = 1;
        G[b-1][a-1] = 1;
        B.push_back({a-1, b-1});
    }

    auto ret = 0;
    rep(i, M) {
        auto b = B[i];
        G[b.first][b.second] = -1;
        G[b.second][b.first] = -1;

        vector<bool> seen(N, 0);
        deque<int> que;
        que.push_back(0);
        while(!que.empty()) {
            auto node = que.front();
            que.pop_front();
            if(seen[node]) {
                continue;
            }
            seen[node] = true;
            rep(i, N) {
                if(G[node][i] == 1) {
                    que.push_back(i);
                }
            }
        }
        bool ok = false;
        rep(i, N) {
            if(seen[i] == false) {
                ok = true;
            }
        }
        if(ok)
            ret++;

        G[b.first][b.second] = 1;
        G[b.second][b.first] = 1;
    }
    cout << ret << endl;

    return 0;
}
