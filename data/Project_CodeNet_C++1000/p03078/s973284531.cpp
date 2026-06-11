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

int main(){
    int x, y, z, K;
    cin >> x >> y >> z >> K;

    vector<ll> a(x), b(y), c(z);
    REP(i, x) cin >> a[i];
    REP(i, y) cin >> b[i];
    REP(i, z) cin >> c[i];

    vector<ll> ab;
    REP(i, x) REP(j, y) {
        ab.push_back(a[i] + b[j]);
    }
    sort(ALL(ab));
    reverse(ALL(ab));
    ll size_ = min(K, x*y); 
    ab.resize(size_);

    vector<ll> ans;
    REP(i, ab.size()) REP(j, z) {
        ans.push_back(ab[i] + c[j]);
    }
    sort(ALL(ans));
    reverse(ALL(ans));

    REP(i, K) {
        cout << ans[i] << endl;
    }

    return 0;
}
