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
    int n;
    cin >> n;
    vector<int> a(n);
    double gokei = 0;
    REP(i, n) cin >> a[i];
    REP(i, n) gokei += a[i];
    gokei /= (double)n;
    double max_ = INF;
    int ans;
    REP(i, n) {
        //cout << abs(gokei - a[i]) << endl;
        if(abs(gokei - a[i]) < max_) {
            max_ = abs(gokei - a[i]);
            ans = i;
        }
    }
    
    cout << ans << endl;

    return 0;
}