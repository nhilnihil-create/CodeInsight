#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for (int (i) = 0 ; (i) < (int)(n) ; ++(i))
#define REPN(i, m, n) for (int (i) = m ; (i) < (int)(n) ; ++(i))
#define REP_REV(i, n) for (int (i) = (int)(n) - 1 ; (i) >= 0 ; --(i))
#define REPN_REV(i, m, n) for (int (i) = (int)(n) - 1 ; (i) >= m ; --(i))

#define INF 2e9
#define INF_LL 1LL<<60
#define ll long long
#define ALL(v) (v).begin(), (v).end()
typedef pair<ll, ll> P;

int main(){
    string st;
    int k;
    cin >> st >> k;

    set<string> ans;
    string s;

    REP(i, st.length()) {
        s = st.substr(i, 1);
        ans.insert(s);
    }

    if(1 < st.length()) {
        REP(i, st.length()-1) {
            s = st.substr(i, 2);
            ans.insert(s);
        }
    }

    if(2 < st.length()) {
        REP(i, st.length()-2) {
            s = st.substr(i, 3);
            ans.insert(s);
        }
    }


    if(3 < st.length()) {
        REP(i, st.length()-3) {
            s = st.substr(i, 4);
            ans.insert(s);
        }
    }

    if(4 < st.length()) {
        REP(i, st.length()-4) {
            s = st.substr(i, 5);
            ans.insert(s);
        }
    }

    auto itr = ans.begin();
    REP(i, k) {

    }
    REP(i, k-1) {
        itr++;
    }
    cout << *itr << endl;

    return 0;
}
