#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
const ll MAX=1001001;
const ll MOD=1000000007;
int main()
{
    ll INF=10000000;
    ll n, m;
    cin>>n>>m;
    ll ans=0;
    vector<vector<char>> maze(n, vector<char>(m));
    rep(i, n) {
        rep(j, m) {
            cin>>maze[i][j];
        }
    }

    vector<vector<ll>> d(n, vector<ll>(m));
    ll dx[4]={ 1, 0, -1, 0 }, dy[4]={ 0, 1, 0, -1 };

    rep(i, n) {
        rep(j, m) {
            d[i][j]=INF;
        }
    }
    queue<P> que;
    rep(i, n) {
        rep(j, m) {
            if (maze[i][j]=='#') {
                que.push(pair<int, int>(i, j));
                d[i][j]=0;
            }
        }
    }
    while (!que.empty()) {
        P p=que.front();que.pop();
        for (ll i=0; i<4;i++) {
            ll nx=p.first+dx[i], ny=p.second+dy[i];

            if (0<=nx&&nx<n&&0<=ny&&ny<m) {

                if (d[nx][ny]==INF) {
                    d[nx][ny]=d[p.first][p.second]+1;
                    que.push(P(nx, ny));
                }
            }
        }
    }
    rep(i, n) {
        rep(j, m) {
            ans=max(ans, d[i][j]);
        }
    }
    cout<<ans<<endl;
}