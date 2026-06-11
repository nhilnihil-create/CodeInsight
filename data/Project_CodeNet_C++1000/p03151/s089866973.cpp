
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
    ll n;
    cin >> n;
    vector<ll> a(n), b(n);
    ll suma = 0, sumb = 0;
    REP(i, n) {
        cin >> a[i];
        suma += a[i];
    }
    REP(i, n) {
        cin >> b[i];
        sumb += b[i];
    }

    if(suma < sumb) {
        cout << "-1" << endl;
        return 0;
    }

    vector<ll> sa(n);
    REP(i, n) sa[i] = a[i] - b[i];
    sort(ALL(sa));
    int ans = 0;
    ll herasu = 0;
    REP(i, n) {
        if(sa[i] < 0) {
            ans++;
            herasu += sa[i];
        }
    }

    REP_REV(i, n) {
        if(herasu >= 0) break;
        ans++;
        herasu += sa[i];
    }

    cout << ans << endl;

    return 0;
}