#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for (ll (i) = 0 ; (i) < (ll)(n) ; ++(i))
#define REPN(i, m, n) for (ll (i) = m ; (i) < (ll)(n) ; ++(i))
#define REP_REV(i, n) for (ll (i) = (ll)(n) - 1 ; (i) >= 0 ; --(i))
#define REPN_REV(i, m, n) for (ll (i) = (ll)(n) - 1 ; (i) >= m ; --(i))

#define INF 1e9 + 1
#define INF_LL 1LL<<60
#define ll long long

#define MAX_V 105

#define MAX_N 100
#define MAX_M 100

int main(){
    int n, a, b;
    cin >> n >> a >> b;
    
    int pos_alice = a;
    int pos_bolys = b;

    while(1) {
        /* alice */
        if(a+1 != b) {
            a++;
        } else {
            if(a == 1) {
                cout << "Borys" << endl;
                return 0;
            } else {
                a--;
            }
        }
        /* bolys */
        if(a+1 != b) {
            b--;
        } else {
            if(b == n) {
                cout << "Alice" << endl;
                return 0;
            } else {
                b++;
            }
        }
    }

    return 0;
}