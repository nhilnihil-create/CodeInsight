#include "bits/stdc++.h"
using namespace std;
#define ll long long int
#define rep(i,n) for( int i = 0; i < n; i++ )
#define rrep(i,n) for( int i = n; i >= 0; i-- )
#define REP(i,s,t) for( int i = s; i <= t; i++ )
#define RREP(i,s,t) for( int i = s; i >= t; i-- )
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define INF 2000000000
#define mod 1000000007
#define INF2 1000000000000000000
int D[31][31];
int c[510][510];
int cnt[3][31];
int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N, C;
    cin >> N >> C;
    
    
    rep(i, C) rep(j, C) cin >> D[i][j];
    
    rep(i, N) rep(j, N) cin >> c[i][j];
    rep(i, N) rep(j, N) c[i][j]--;
    rep(i, N) {
        rep(j, N) {
            cnt[(i + j) % 3][c[i][j]]++;
        }
    }
    int ans = INF;
    rep(i, C) {
        rep(j, C) {
            rep(k, C) {
                if(i == j || j == k || i == k)continue;
                int cost = 0;
                rep(s, C) {
                    cost += cnt[0][s] * D[s][i];
                    cost += cnt[1][s] * D[s][j];
                    cost += cnt[2][s] * D[s][k];
                }
                //cout << i << " " << j << " " << k << " " << cost << endl;
                ans = min(ans, cost);
            }
        }
    }
    cout << ans << endl;

    return 0;
}
