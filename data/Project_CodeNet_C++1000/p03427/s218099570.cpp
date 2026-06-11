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
    ll n;
    cin >> n;
    vector<ll> keta;
    while(1) {
        keta.push_back(n % 10);
        n /= 10;
        if(n == 0) break;
    }

    ll keta_size = keta.size();
    reverse(ALL(keta));

    ll dp[keta_size][2];    /* 0: いっしょ、1: より小さい */
    dp[0][0] = keta[0];
    dp[0][1] = keta[0] - 1;

    REP(i, keta.size()-1) {
        /* いっしょからいっしょ */
        dp[i+1][0] = dp[i][0] + keta[i+1];

        /* いっしょからより小さい */
        dp[i+1][1] = dp[i][0] + keta[i+1] - 1;

        /* より小さいからより小さい */
        dp[i+1][1] = dp[i][1] + 9;
    }

    cout << max(dp[keta_size-1][0], dp[keta_size-1][1]) << endl;

    return 0;
}