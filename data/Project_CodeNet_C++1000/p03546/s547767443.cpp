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


int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int H, W;
    cin >> H >> W;
    int c[10][10];
    rep(i, 10) rep(j, 10) cin >> c[i][j];
    rep(k, 10) {
        rep(i, 10) {
            rep(j, 10) {
                c[i][j] = min(c[i][j], c[i][k] + c[k][j]);
            }
        }
    }
    int ans = 0;
    rep(i, H) {
        rep(j, W){
            int A; cin >> A;
            if(A == -1) continue;
            ans += c[A][1];
        }
    }
    cout << ans << endl;

    return 0;
}
