//参考 :https://www.hamayanhamayan.com/entry/2017/12/04/034531
#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for (ll (i) = 0 ; (i) < (ll)(n) ; ++(i))
#define REPN(i, m, n) for (ll (i) = m ; (i) < (ll)(n) ; ++(i))
#define REP_REV(i, n) for (ll (i) = (ll)(n) - 1 ; (i) >= 0 ; --(i))
#define REPN_REV(i, m, n) for (ll (i) = (ll)(n) - 1 ; (i) >= m ; --(i))

#define INF             2e9
#define INF_LL          1LL<<60
#define ll              long long
#define Ceil(x, n)      (((((x))+((n)-1))/n))
#define CeilN(x, n)     (((((x))+((n)-1))/n)*n)
#define FloorN(x, n)    ((x)-(x)%(n))
#define ALL(x)          (x).begin(),(x).end()
#define print(x)        cout << (x) << endl
#define printa(x)       REP(i, x.size()) cout << x[i] << endl
typedef pair<ll, ll>    P;

int imos[30][100005];

int main() {
    int n, c;
    cin >> n >> c;


    REP(i, n) {
        int x, y, z;
        cin >> x >> y >> z;
        x--, z--;
        imos[z][x]++;
        imos[z][y]--;
    }

    REP(i, c) REPN(j, 1, 100005) imos[i][j] += imos[i][j-1];
    REP(i, c) REP(j, 100005) if(imos[i][j] >= 2) imos[i][j] = 1;

    int ans = 0;
    REP(i, 100005) {
        int tmp = 0;
        REP(j, c) tmp += imos[j][i];
        ans = max(ans, tmp);
    }

    cout << ans << endl;

    return 0;
}