#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for (ll (i) = 0 ; (i) < (ll)(n) ; ++(i))
#define REPN(i, m, n) for (ll (i) = m ; (i) < (ll)(n) ; ++(i))
#define REP_REV(i, n) for (ll (i) = (ll)(n) - 1 ; (i) >= 0 ; --(i))
#define REPN_REV(i, m, n) for (ll (i) = (ll)(n) - 1 ; (i) >= m ; --(i))

#define INF 2e9
#define INF_LL 1LL<<60
#define ll long long

#define MAX_V 105

int main(){
    int n;
    cin >> n;
    int ans = 0;
    vector<int> a(n);
    REP(i, n) cin >> a[i];

    int tmp = 1;
    REP(i, n-1) {
        if(a[i] == a[i+1]) {
            tmp++;
        } else {
            ans += tmp / 2;
            tmp = 1;
        }
    }

    ans += tmp / 2;

    cout << ans << endl;

    return 0;
}
