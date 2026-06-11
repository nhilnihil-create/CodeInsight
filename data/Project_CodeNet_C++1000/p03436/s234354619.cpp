#include <bits/stdc++.h>
#define rep(i, n) for(ll i = 0; i < n; i++)
#define repr(i, n) for(ll i = n; i >= 0; i--)
#define reprr(i, m, n) for (ll i = m; i < n; i++)
#define inf 2e9
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
using Graph = vector<vector<pair<ll, ll>>>;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};

int main()
{
    ll H, W; cin >> H >> W;
    vector<string> board(H); rep(i, H) cin >> board[i];

    vvll costs(H, vll(W, inf));
    priority_queue<pair<ll, pair<ll, ll>>, vector<pair<ll, pair<ll, ll>>>, greater<pair<ll, pair<ll, ll>>>> que;
    que.push({0, {0, 0}});
    costs[0][0] = 0;

    while (que.size()) {
        auto p = que.top(); que.pop();
        ll cost = p.first;
        auto point = p.second;

        if (costs[point.first][point.second] < cost) continue;

        rep(i, 4) rep(j, 4) {
            ll ny = point.first + dy[i];
            ll nx = point.second + dx[i];
            if (0 <= nx && nx < W && 0 <= ny && ny < H && board[ny][nx] == '.' && costs[point.first][point.second] + 1 < costs[ny][nx]) {
                costs[ny][nx] = costs[point.first][point.second] + 1;
                que.push({costs[ny][nx], {ny, nx}});
            }
        }
    }

    ll b_count = 0;
    rep(i, H) {
        rep(j, W) {
            b_count += (board[i][j] == '#');
        }
    }

    if (costs[H-1][W-1] == inf) {
        cout << -1 << endl;
        return 0;
    }

    cout << H * W - costs[H-1][W-1] - b_count - 1 << endl;
    return 0;
}