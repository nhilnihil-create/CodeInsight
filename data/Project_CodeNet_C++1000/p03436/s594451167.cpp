#include <bits/stdc++.h>
// #include <atcoder/all>
#define ll long long int
#define ld long double
#define yorn(f) cout<<((f)?"Yes":"No")<<endl;
#define YORN(f) cout<<((f)?"YES":"NO")<<endl;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repi(i, n) for (ll i = 1; i < (ll)(n); i++)
#define all(x) (x).begin(), (x).end()
#define put(x) cout << x << endl;
#define println(x) cout << x << endl;
using namespace std;
// using namespace atcoder;
void Main()
{
    ll H, W;
    cin >> H >> W;
    vector<string> s(H);
    rep(i, H) cin >> s[i];

    ll sx = 0, sy = 0;
    ll gx = W - 1, gy = H - 1;

    ll INF = 1e18;
    vector<vector<ll>> d(H, vector<ll>(W, INF));
    
    typedef pair<ll, ll> P;
    queue<P> que;
 
    que.push(P(sx, sy));
    d[sy][sx] = 0;

    int dx[] = { -1, 0, 1, 0 };
    int dy[] = { 0, -1, 0, 1 };

    while (que.empty() == false) {
        P q = que.front();
        ll x = q.first;
        ll y = q.second;
        que.pop();

        rep(i, 4) {
            ll x2 = dx[i] + x;
            ll y2 = dy[i] + y;
            if (x2 < 0 || W <= x2 || y2 < 0 || H <= y2) {
                continue;
            }
            if (d[y2][x2] != INF) {
                // already visited
                continue;
            }
            if (s[y2][x2] == '.') {
                d[y2][x2] = d[y][x] + 1;
                que.push(P(x2, y2));
            }
        }
    }
    
    ll cost = d[gy][gx];
    if (cost == INF) {
        put(-1);
        return;
    }

    ll black = 0;
    rep(i, s.size()) {
        rep(j, s[i].size()) {
            if (s[i][j] == '#') {
                black++;
            }
        }
    }

    ll res = H * W - black - cost - 1;
    put(res);

}
signed main(){ Main();return 0;}