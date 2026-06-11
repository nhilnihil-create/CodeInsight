
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
    int n = s.size();
    vector<bool> used(26, false);
    REP(i, n) {
        used[s[i] - 'a'] = true;
    }

    if(s == "zyxwvutsrqponmlkjihgfedcba") {
        cout << "-1" << endl;
        return 0;
    }

    if(n < 26) {
        REP(i, 26) {
            if(!used[i]) {
                cout << s << (char)('a' + i) << endl;
                return 0;
            }
        }
    }

    int nozoku = 0;
    bool find = false;
    REP_REV(i, n) {
        int idx = s[i] - 'a';
        REPN(j, idx+1, 26) {
            //cout << (char)('a'+j);
            if(!used[j]) {
                //cout << "aaaaaa" << endl;
                s[i] = 'a' + j;
                find = true;
                break;
            } 
        }
        if(find) break;
        //cout << endl;
        used[idx] = false;
        nozoku++;
    }

    cout << s.substr(0, n-nozoku) << endl;
    

    return 0;
}