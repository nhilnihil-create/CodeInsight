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
    string s;
    cin >> s;
    string miru = "KIHBR";

    if(s.size() > 9) {
        cout << "NO" << endl;
        return 0;
    }
    int idx = 0;
    REP(i, s.size()) {
        if(s[i] != miru[idx]) {
            if(s[i] != 'A') {
                cout << "NO" << endl;
                return 0;
            }
        } else {
            idx++;
        }
    }

    if(idx != 5) {
        cout << "NO" << endl;
        return 0;
    }

    REP(i, s.size()-1) {
        if(s[i+1] == 'A') {
            if(s[i] != 'H' && s[i] != 'B' && s[i] != 'R') {
                cout << "NO" << endl;
                return 0;
            }
        }
    }
    cout << "YES" << endl;

    return 0;
}