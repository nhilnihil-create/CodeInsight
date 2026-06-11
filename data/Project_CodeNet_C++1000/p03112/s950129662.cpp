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

vector<ll> teraa(100005);
vector<ll> jin(100005);

ll comp(ll x, ll idx, ll idx2, ll ans) {
    ll tmp = abs(x - jin[idx]) + abs(jin[idx] - teraa[idx2]);
    ans = min(ans, tmp);
    tmp = abs(x - teraa[idx2]) + abs(jin[idx] - teraa[idx2]);
    ans = min(ans, tmp);

    return ans;
}

int main(){
    ll a, b, q;
    cin >> a >> b >> q;
    jin.resize(a), teraa.resize(b);
    REP(i, a) cin >> jin[i];
    REP(i, b) cin >> teraa[i];
    sort(ALL(jin));
    sort(ALL(teraa));

    REP(i, q) {
        ll x;
        cin >> x;
        ll ans = INF_LL;

        /* 左神、左寺 */
        ll idx = distance(jin.begin(), upper_bound(ALL(jin), x));
        if(idx != 0) idx--;
        ll idx2 = distance(teraa.begin(), upper_bound(ALL(teraa), x));
        if(idx2 != 0) idx2--;
        ans = comp(x, idx, idx2, ans);

        /* 左神、右寺 */
        idx = distance(jin.begin(), upper_bound(ALL(jin), x));
        if(idx != 0) idx--;
        idx2 = distance(teraa.begin(), lower_bound(ALL(teraa), x));
        if(idx2 == b) idx2 = b - 1;  
        ans = comp(x, idx, idx2, ans);

        /* 右神、左寺 */
        idx = distance(jin.begin(), lower_bound(ALL(jin), x));
        if(idx == a) idx = a - 1;        
        idx2 = distance(teraa.begin(), upper_bound(ALL(teraa), x));
        if(idx2 != 0) idx2--;
        ans = comp(x, idx, idx2, ans);

        /* 右神、右寺 */
        idx = distance(jin.begin(), lower_bound(ALL(jin), x));
        if(idx == a) idx = a - 1;   
        idx2 = distance(teraa.begin(), lower_bound(ALL(teraa), x));
        if(idx2 == b) idx2 = b - 1;
        ans = comp(x, idx, idx2, ans);   

        cout << ans << endl;
    }

    return 0;
}
