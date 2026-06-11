#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for (ll (i) = 0 ; (i) < (ll)(n) ; ++(i))
#define REPN(i, m, n) for (ll (i) = m ; (i) < (ll)(n) ; ++(i))
#define REP_REV(i, n) for (ll (i) = (ll)(n) - 1 ; (i) >= 0 ; --(i))
#define REPN_REV(i, m, n) for (ll (i) = (ll)(n) - 1 ; (i) >= m ; --(i))

#define INF 2e8
#define INF_LL 1LL<<60
#define ll long long
#define MAX_V 100005

int main() {
    int n;
    cin >> n;
    vector<ll> a(n);

    REP(i, n) cin >> a[i];

    int left = 0, right = 0;
    ll ans = 0;
    ll now_xor = 0;
    ll now_sum = 0;
    int i, j = 0;

    REP(i, n) {
        while(1) {
            if(j == n) break;
            if((now_xor^a[j]) != (now_sum + a[j])) break;
            now_xor ^= a[j];
            now_sum += a[j];
            //cout << now_xor << " " << now_sum << endl;
            j++;
        }

        ans += j - i;
        //cout << j << " " << i << " " << j-i << endl;

        now_sum -= a[i];
        now_xor ^= a[i];
    }

    cout << ans << endl;
}
 