
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
    int h, w, d;
    cin >> h >> w >> d;
    vector<ll> basyo(h*w+1);
    REP(i, h) REP(j, w) {
        int a;
        cin >> a;
        basyo[a] = i * w + j;
    } 

    vector<ll> ruiseki[d];
    REP(i, d) ruiseki[i].push_back(0);

    REPN(i, 1, h*w+1) {
        if(i+d > h*w) continue;
        int x = basyo[i] / w, y = basyo[i] % w;
        int x2 = basyo[i+d] / w, y2 = basyo[i+d] % w;
        int cost = abs(x-x2) + abs(y-y2);
        int mae = ruiseki[i%d][ruiseki[i%d].size()-1];
        ruiseki[i%d].push_back(cost + mae);
        //cout << i << " " <<  i+d << " " << cost << endl;
    }

    REP(i, ruiseki[0].size()) {
        //cout << ruiseki[0][i] << endl;
    }

    int q;
    cin >> q;
    REP(query, q) {
        int a, b;
        cin >> a >> b;
        if(a == b) cout << "0" << endl;
        else if(a%d != 0) cout << ruiseki[a%d][b/d] - ruiseki[a%d][a/d] << endl;
        else cout << ruiseki[a%d][b/d-1] - ruiseki[a%d][(a-d)/d] << endl;
    }

    return 0;
}