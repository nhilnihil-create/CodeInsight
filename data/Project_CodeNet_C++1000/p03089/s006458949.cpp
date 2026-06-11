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

#define MAX_N 100
#define MAX_M 100

int main() {
    int n;
    cin >> n;
    vector<int> b(n), ans;
    REP(i, n) cin >> b[i];

    REP(i, n) {
        bool seikou = false;
        int idx;
        REP(j, b.size()) {
            if(j+1 == b[j]) {
                seikou = true;
                idx = j;
            }
        }
        if(seikou) {
            ans.push_back(b[idx]);
            b.erase(b.begin()+idx);
        } else if (!seikou) {
            cout << "-1" << endl;
            return 0;
        }
    }

    reverse(ans.begin(), ans.end());
    REP(i, ans.size()) {
        cout << ans[i] << endl;
    } 
}