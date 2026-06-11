#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <functional>
#include <algorithm>
#include <climits>
#include <cmath>
#include <iomanip>
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
#define int long long

int sum[31][31];
int D[31][31];
int c[510][510];
int cnt[3][31];
signed main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N, C;
    cin >> N >> C;
    rep(i, C) {
        rep(j, C) {
            cin >> D[i][j];
        }
    }
    rep(i, N) {
        rep(j, N) {
            cin >> c[i][j];
            c[i][j]--;
        }
    }
    rep(i, N) {
        rep(j, N) {
            cnt[(i + j) % 3][c[i][j]]++;
        }
    }
    int ans = INF;
    rep(i, C) {
        rep(j, C) {
            if(i == j) continue;
            rep(k, C){
                if(i == k || j == k) continue;
                int tmp = 0;
                for(int a = 0; a < C; a++) {
                    tmp += cnt[0][a] * D[a][i];
                    tmp += cnt[1][a] * D[a][j];
                    tmp += cnt[2][a] * D[a][k];
                }
                //cout << i << " " << j << " " << k << " " << tmp << endl;
                ans = min(ans, tmp);
            }
        }
    }
    cout << ans << endl;




    return 0;
}
