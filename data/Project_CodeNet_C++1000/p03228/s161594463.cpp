#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for (ll (i) = 0 ; (i) < (ll)(n) ; ++(i))
#define REPN(i, m, n) for (ll (i) = m ; (i) < (ll)(n) ; ++(i))
#define REP_REV(i, n) for (ll (i) = (ll)(n) - 1 ; (i) >= 0 ; --(i))
#define REPN_REV(i, m, n) for (ll (i) = (ll)(n) - 1 ; (i) >= m ; --(i))

#define INF 1e9 + 1
#define INF_LL 1LL<<60
#define ll long long

#define MAX_V 105

#define MAX_N 100
#define MAX_M 100

int main(){
    int a, b, k;
    cin >> a >> b >> k;
    int idx = 0;
    REP(i, k) {
        if(idx % 2 == 0) {
            /* 高橋 */
            a /= 2;
            b += a;
        } else {
            /* 青木 */
            b /= 2;
            a += b;
        }
        idx++;
    }

    cout << a << " " << b << endl;

    return 0;
}