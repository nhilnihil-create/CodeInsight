
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
    map<int, int> st;
    int n;
    cin >> n;
    vector<int> d(n);
    REP(i, n) cin >> d[i];
    int m;
    cin >> m;
    vector<int> t(m);
    REP(i, m) cin >> t[i];

    REP(i, n) {
        st[d[i]]++;
    }

    REP(i, m) {
        if(st[t[i]] > 0) {
            st[t[i]]--;
        } else {
            cout << "NO" << endl;
            return 0;
        }
    }

    cout << "YES" << endl;
    return 0;
}