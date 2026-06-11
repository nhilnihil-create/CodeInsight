
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

    string t;
    vector<int> idx;
    REP(i, s.size()) {
        if(s[i] != 'x') {
            t += s[i];
            idx.push_back(i);
        }
    }

    REP(i, t.size()/2) {
        if(t[i] != t[t.size()-1-i]) {
            cout << -1 << endl;
            return 0;
        }
    }
    //cout << t.size() << endl;
    //cout << idx[t.size()/2] << " " << idx[t.size() - 1 - t.size()/2] << endl;
    if(t.size() == 0) {
        cout << "0" << endl;
        return 0;
    }
    int kosu = 0;
    int id = 0, id2 = s.size()-1;
    if(t.size()%2 == 1) {
        while(1) {
            if(id == idx[t.size()/2] && id2 == idx[t.size() - 1 - t.size()/2]) break;
            if(s[id] != s[id2]) {
                if(s[id] != 'x') {
                    kosu++, id2--;
                } else if(s[id2] != 'x') {
                    kosu++, id++;
                }
            } else {
                id++, id2--;
            }
        }        
    } else {
        while(1) {
            if(id == idx[t.size()/2 - 1] && id2 == idx[t.size() - t.size()/2]) break;
            if(s[id] != s[id2]) {
                if(s[id] != 'x') {
                    kosu++, id2--;
                } else if(s[id2] != 'x') {
                    kosu++, id++;
                }
            } else {
                id++, id2--;
            }
        }        
    }


    cout << kosu << endl;
    return 0;
}