#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for (ll (i) = 0 ; (i) < (ll)(n) ; ++(i))
#define REPN(i, m, n) for (ll (i) = m ; (i) < (ll)(n) ; ++(i))
#define REP_REV(i, n) for (ll (i) = (ll)(n) - 1 ; (i) >= 0 ; --(i))
#define REPN_REV(i, m, n) for (ll (i) = (ll)(n) - 1 ; (i) >= m ; --(i))

#define INF 2e9
#define INF_LL 1LL<<60
#define ll long long

typedef pair<ll, ll> P;

ll power(int x) {
    int tmp = 1;
    REP(i, x) tmp *= 2;
    return tmp;
}

int main(){
    int m, k;
    cin >> m >> k;

    if(m == 0) {
        if(k == 0) cout << "0 0" << endl;
        else cout << "-1" << endl;
        return 0;
    }

    if(m == 1) {
        if(k == 0) cout << "0 0 1 1" << endl;
        else cout << "-1" << endl;
        return 0;
    }

    if(power(m) <= k) {
        cout << "-1" << endl;
        return 0;
    }

    vector<ll> ans(power(m)*2);

    if(k == 0) {
        REP(i, power(m)) {
            cout << i << " " << i << endl;
        } 
        return 0;
    }

    ans[0] = 0, ans[1] = k, ans[2] = 0;
    int idx = 3;

    REPN(i, 1, power(m)) {
        if(i == k) continue;
        ans[idx] = i;
        idx++;
    }

    ans[idx] = k;
    idx++;

    REPN_REV(i, 1, power(m)) {
        if(i == k) continue;
        ans[idx] = i;
        idx++;
    }    

    REP(i, ans.size()) cout << ans[i] << " ";
    cout << endl;

    return 0;
}
