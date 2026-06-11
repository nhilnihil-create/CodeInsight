
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
    string s;
    cin >> s;
    ll n = s.size();
    vector<ll> cnv;
    
    REP(i, n) {
        if(s[i] == 'A') {
            cnv.push_back(0);
        } else if (s[i] == 'B') {
            if((i < n-1) && s[i+1] == 'C') {
                i++;
                cnv.push_back(1);
            } else {
                cnv.push_back(-1);
            }
        } else {
            cnv.push_back(-1);
        }
    }

    ll ans = 0;
    ll front = 0;
    REP(i, cnv.size()) {
        //cout << cnv[i] << endl;
        if(cnv[i] == 0) {
            front++;
        } else if(cnv[i] == 1) {
            ans += front;
        } else {
            front = 0;
        }
    }

    cout << ans << endl;

    return 0;
}