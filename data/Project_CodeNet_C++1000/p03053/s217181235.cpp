#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <random>
#include <chrono>
#include <tuple>
#include <random>
#include <cmath>

using namespace std;

typedef long long ll;
typedef long double ld;
#define fastInp cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

const ll SZ = 2009, INF = 1e9 * 1e9 + 10;

char grid[SZ][SZ];

vector<pair<ll, ll>> dir = { {-1, 0}, {1, 0}, {0, 1}, {0, -1}};
bool used[SZ][SZ];
ll dist[SZ][SZ];

int main()
{
    fastInp;

    ll h, w;
    cin >> h >> w;


    queue<pair<ll, ll>> q;

    
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> grid[i][j];
            
            if (grid[i][j] == '#') {
                used[i][j] = 1;
                dist[i][j] = 0;
                q.push({i, j});
            }
        }
    }

    while (!q.empty()) {
        pair<ll, ll> v=  q.front();
        q.pop();

        for (auto cur : dir) {
            if (cur.first + v.first >= 0 && cur.second + v.second >= 0 && cur.first + v.first < h && cur.second + v.second < w) {
                if (!used[cur.first + v.first][cur.second + v.second]) {
                    used[cur.first + v.first][cur.second + v.second] = 1;
                    dist[cur.first + v.first][cur.second + v.second] = dist[v.first][v.second] + 1;
                    q.push({cur.first + v.first, cur.second + v.second});
                }
            }
        }
    }

    ll ans = 0;
    for (int i= 0; i < h; i++) {
        for (int j= 0; j < w; j++) {
            ans = max(ans, dist[i][j]);
        }
    }

    cout << ans;
    
    return 0;
}