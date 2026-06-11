#include<bits/stdc++.h>
#define forr(i, a, b) for(int i = (a); i < (b); i++)
#define rep(i,n) for(int i = 0; i < (n); i++)
#define rrep(i,n) for(int i = 1; i <= (n); i++)
#define ALL(a) (a.begin()),(a.end())
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<ll, ll> LP;
const ll LINF = 1LL<<60;
const int INF = 1001001001;
const int MOD = 1000000007;

/* --------------------------------------------------- */

int main() {
    string s, t;
    cin >> s >> t;
    map<char, int> ms, mt;
    rep(i, s.size()) {
        ms[s[i]]++;
    }
    rep(i, t.size()) {
        mt[t[i]]++;
    }
    vector<int> svec, tvec;
    for(auto x : ms) {
        svec.push_back(x.second);
    }
    for(auto x : mt) {
        tvec.push_back(x.second);
    } 
    sort(ALL(svec));
    sort(ALL(tvec));
    bool ans = true;
    if(svec.size() != tvec.size()) ans = false;
    else {
        rep(i, svec.size()) {
            if(svec[i] != tvec[i]) ans = false;
        }
    }

    cout << (ans ? "Yes" : "No") << endl;

    return 0;
}