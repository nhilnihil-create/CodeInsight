#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
// #define int long long

template <class T>
bool INRANGE(T x, T a, T b) { return a <= x && x <= b; }
template <class T>
inline bool chmin(T &a, T b)
{
    if (a > b)
    {
        a = b;
        return true;
    }
    return false;
}
template <class T>
inline bool chmax(T &a, T b)
{
    if (a < b)
    {
        a = b;
        return true;
    }
    return false;
}

#define REP(i, n) for (int i = 0; i < (n); ++i)
#define RREP(i, n) for (int i = (n); i >= 0; --i)
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define RFOR(i, a, b) for (int i = (a); i >= (b); --i)
#define ALL(v) (v).begin(), (v).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" \
                      << " " << __FILE__ << endl;

typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<vi> vvi;
typedef pair<int, int> pii;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int H, W;
    cin >> H >> W;

    vs m(H);
    REP(i, H) cin >> m[i];

    queue<pii> q;
    q.push(pii(0, 0));
    vvi dist(H, vi(W, -1));
    dist[0][0] = 1;

    int dx[] = {0, 1, 0, -1};
    int dy[] = {-1, 0, 1, 0};
    while (!q.empty())
    {
        pii now = q.front();
        q.pop();

        REP(i, 4) {
            int nx = now.first + dx[i];
            if (!INRANGE(nx, 0, W-1)) continue;
            int ny = now.second + dy[i];
            if (!INRANGE(ny, 0, H-1)) continue;

            if (m[ny][nx] == '#') continue;
            if (dist[ny][nx] != -1) continue;

            q.push(pii(nx, ny));
            dist[ny][nx] = dist[now.second][now.first] + 1;
        }
    }


    
    if (dist[H-1][W-1] == -1) {
        cout << -1 << endl;
    } else {
        int cnt = 0;
        for (string l : m) {
            for (char c : l) if (c == '#') cnt++;
        }
        int nw = cnt + dist[H-1][W-1];

        cout << H*W - nw << endl;
    }

    return 0;
}
