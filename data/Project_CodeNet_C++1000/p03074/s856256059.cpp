
/* にぶたん二回 */
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
    int n, k;
    string s;
    cin >> n >> k >> s;
    vector<P> array_;
    int tmp_j = 0, tmp_s = 0;
    int zenkai = 0;

    REP(i, n) {
        if(s[i] == '0') {
            /* 順立ち */
            if(zenkai == 0) {
                tmp_j++;
            } else {
                array_.push_back({tmp_j, tmp_s});
                tmp_j = 1;
                tmp_s = 0;
                zenkai = 0;
            }
        } else {
            /* 逆立ち */
            if(zenkai == 1) {
                tmp_s++;
            } else {
                zenkai = 1;
                tmp_s++;
            }
        }
    }
    array_.push_back({tmp_j, tmp_s});

    REP(i, array_.size()) {
        //cout << array_[i].first << " " << array_[i].second << endl;
    }

    if(array_[0].first == 0) {
        if(k >= array_.size() - 1) {
            cout << n << endl;
            return 0;
        }
    } else {
        if(k >= array_.size()) {
            cout << n << endl;
            return 0;
        }
    }

    /* 累積和 */
    vector<ll> ruiseki(array_.size()+1);
    ruiseki[0] = 0;
    REPN(i, 1, array_.size()+1) {
        ruiseki[i] = ruiseki[i-1] + array_[i-1].first + array_[i-1].second;
    }

    ll ans = 0;

    REP(i, array_.size() - k + 1) {    
        ll tmp = ruiseki[i+k] - ruiseki[i];
        if(i != 0) {
            tmp += array_[i-1].second;
        }
        ans = max(ans, tmp);
    }

    cout << ans << endl;

    return 0;
}