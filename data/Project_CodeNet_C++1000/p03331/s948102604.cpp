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

int main(){
    int n;
    cin >> n;

    int ans = 1000000;

    REPN(i, 1, n) {
        int a = n - i;
        int b = i;
        int tmp = 0;
        while(a > 0) {
            tmp += a % 10;
            a /= 10;
        }
        while(b > 0) {
            tmp += b % 10;
            b /= 10;
        }
        ans = min(tmp, ans);
    }

    cout << ans << endl;

    return 0;
}