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
    int n;
    cin >> n;
    string s;
    cin >> s;

    vector<int> kuro(s.size(), 0);
    vector<int> shiro(s.size(), 0);
    int tmp_kuro = 0, tmp_shiro = 0;
    REP(i, s.size()) {
        if(s[i] == '.') {
            tmp_shiro++;
        } else {
            tmp_kuro++;
        }
        kuro[i] = tmp_kuro;
        shiro[i] = tmp_shiro;
    }

    int ans = INF, tmp = 0;

    REP(i, s.size()+1) {
        if(i == 0){
            tmp = shiro[s.size()-1];
        } else if (i == s.size()) {
            tmp = kuro[s.size()-1];
        } else {
            tmp = kuro[i-1];
            tmp += shiro[s.size()-1] - shiro[i-1];
        }

        ans = min(ans, tmp);
    }

    cout << ans << endl;

    return 0;
}