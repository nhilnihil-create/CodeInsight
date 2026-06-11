
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
    ll k, a, b;
    cin >> k >> a >> b;
    ll ans = 1;
    if(a+1 < b) {
        /* たまったら交換するのがいい */
        ans = a;
        ll kaisu = max((ll)0, k-(a-1));
        ans += (kaisu / 2) * (b-a);
        if(kaisu % 2 == 1) ans++;
    } else {
        /* 増やし続ける */
        ans += k;
    }

    cout << ans << endl;
    return 0;
}