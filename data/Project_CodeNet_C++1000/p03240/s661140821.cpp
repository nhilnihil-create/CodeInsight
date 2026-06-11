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

signed main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n; cin >> n;
    int x[110], y[110], h[110];
    rep(i, n) cin >> x[i] >> y[i] >> h[i];
    int maximam = 0;
    rep(i, n) maximam = max(maximam, h[i]);
    REP(i, 0, 100) {
        REP(j, 0, 100) {
            REP(H, maximam, maximam + 100) {
                bool ok = true;
                rep(k, n) {
                    int tmpH = max(0, H - abs(x[k] - i) - abs(y[k] - j));
                    if(h[k] != tmpH) ok = false;
                    if(!ok) break;
                }
                if(ok) {
                    cout << i << " " << j << " " << H << endl;
                    return 0;
                }
            }
        }
    }

    return 0;
}
