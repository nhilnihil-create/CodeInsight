#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false); cin.tie(0);
#define FOR(i,s,n) for(int i = (s); i < (n); i++)
#define REP(i,n) FOR(i,0,n)
#define RREP(i,n) for(int i = (n); i >= 0; i--)
#define ALL(n) (n).begin(), (n).end()
#define RALL(n) (n).rbegin(), (n).rend()
#define ATYN(n) cout << ( (n) ? "Yes":"No") << '\n';
#define CFYN(n) cout << ( (n) ? "YES":"NO") << '\n';
#define OUT(n) cout << (n) << '\n';
using ll = long long;
using ull = unsigned long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;

int main(void)
{
    IOS
    const vector<int> dx{0,1,0,-1},
                      dy{1,0,-1,0};
    const char B = '#';
    int H, W;
    cin >> H >> W;
    vector<string> ss(H);
    REP(i,H) cin >> ss[i];

    int ans = 0;
    vector<pii> bfs;
    REP(i,H) REP(j,W) {
        if (ss[i][j] == B) bfs.emplace_back(i,j);
    }

    while(!bfs.empty()) {
        vector<pii> tmp;
        swap(tmp,bfs);

        for(auto p:tmp) {
            REP(i,dx.size()) {
                int ny = p.first + dy[i];
                int nx = p.second+ dx[i];
                if (ny < 0 || H <= ny) continue;
                if (nx < 0 || W <= nx) continue;
                if (ss[ny][nx] == B) continue;
                bfs.emplace_back(ny,nx);
                ss[ny][nx] = B;
            }
        }
        if (!bfs.empty()) ans++;
    }

    cout << ans << '\n';

    return 0;
}