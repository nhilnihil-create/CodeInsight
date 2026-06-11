#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <map>
#include <queue>
#include <cassert>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define ALL(a) (a).begin(), (a).end()
#define rALL(a) (a).rbegin(), (a).rend()
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int iINF = 1001001001;
const long long llINF = 1LL << 60;
int main()
{
    // ABC080-C, 1141, 
    int n; cin >> n;
    vector<vector<int>> f(n, vector<int>(10, 0));
    vector<vector<int>> p(n, vector<int>(11, 0));
    rep(i, n) rep(j, 10) cin >> f[i][j];
    rep(i, n) rep(j, 11) cin >> p[i][j];
    ll ans = -iINF;
    rep(i, 1 << 10) {
        if (i == 0) continue;
        ll tmpans = 0;
        rep(j, n) {
            int c = 0;
            rep(k, 10) {
                c += (i >> k & 1) * f[j][k];
            }
            tmpans += ll(p[j][c]);
        }
        ans = max(ans, tmpans);
    }
    cout << ans << endl;
    return 0;
}