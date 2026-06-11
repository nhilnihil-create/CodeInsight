/* 拡張ダイクストラ */
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
typedef pair<ll, ll>    P;

int main() {
    ll n, k;
    cin >> n >> k;
    vector<ll> v(n);
    REP(i, n) cin >> v[i];

    ll gokei = min(n, k);
    ll ans = 0;

    /* 左からa個、右からb個 */
    REP(a, gokei+1) REP(b, gokei+1-a) {
        ll tmp = 0;
        vector<ll> motsu;
        REP(i, a) {
            motsu.push_back(v[i]);
            tmp += v[i];
        }
        REP(i, b) {
            motsu.push_back(v[n-1-i]);
            tmp += v[n-1-i];
        }

        ll suteru = k - (a + b);
        sort(ALL(motsu));
        REP(i, suteru) {
            if(i == motsu.size()) break;
            if(motsu[i] >= 0) break;
            tmp -= motsu[i];
        }
        ans = max(ans, tmp);
    }

    cout << ans << endl;

    return 0;
}