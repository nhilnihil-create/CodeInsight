
#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for (ll (i) = 0 ; (i) < (ll)(n) ; ++(i))
#define REPN(i, m, n) for (ll (i) = m ; (i) < (ll)(n) ; ++(i))
#define REP_REV(i, n) for (ll (i) = (ll)(n) - 1 ; (i) >= 0 ; --(i))
#define REPN_REV(i, m, n) for (ll (i) = (ll)(n) - 1 ; (i) >= m ; --(i))

#define INF 2e9
#define INF_LL 1LL<<60
#define ll long long


int main(){
    int h, w, n;
    cin >> h >> w >> n;

    int sr, sc;
    cin >> sr >> sc;
    sr--, sc--;

    string s, t;
    cin >> s >> t;

    /* 上方向 */
    int tate = sr;
    REP(i, n) {
        /* 高橋 */
        if(s[i] == 'U') {
            tate--;
            if(tate < 0) {
                cout << "NO" << endl;
                return 0;
            }
        }
        /* 青木 */
        if(t[i] == 'D') {
            if(tate < h-1) tate++; 
        }
    }

    /* 下方向 */
    tate = sr;
    REP(i, n) {
        /* 高橋 */
        if(s[i] == 'D') {
            tate++;
            if(tate > h-1) {
                cout << "NO" << endl;
                return 0;
            }
        }
        /* 青木 */
        if(t[i] == 'U') {
            if(tate > 0) tate--; 
        }
    }

    /* 右方向 */
    int yoko = sc;
    REP(i, n) {
        /* 高橋 */
        if(s[i] == 'R') {
            yoko++;
            if(yoko > w-1) {
                cout << "NO" << endl;
                return 0;
            }
        }
        /* 青木 */
        if(t[i] == 'L') {
            if(yoko > 0) yoko--; 
        }
    }

    /* 左方向 */
    yoko = sc;
    REP(i, n) {
        /* 高橋 */
        if(s[i] == 'L') {
            yoko--;
            if(yoko < 0) {
                cout << "NO" << endl;
                return 0;
            }
        }
        /* 青木 */
        if(t[i] == 'R') {
            if(yoko < w-1) yoko++; 
        }
    }


    cout << "YES" << endl;

    return 0;
}
