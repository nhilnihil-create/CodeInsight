#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i=0;i<ll(n);i++)
ll MOD = 1e9 + 7;
int main() {
    string s, t;
    cin >> s >> t;
    map<char, int> ms,mt;
    map<int, vector<int>> vs, vt;
    rep(i, s.length()){
        if (ms[s[i]] == 0) {
            ms[s[i]] = i;
        }else {
            vs[ms[s[i]]].push_back(i);
        }
    }
    rep(i, t.length()){
        if (mt[t[i]] == 0) {
            mt[t[i]] = i;
        }else {
            vt[mt[t[i]]].push_back(i);
        }
    }
    rep(i, s.length()) {
        if (vs[i] != vt[i]) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}

