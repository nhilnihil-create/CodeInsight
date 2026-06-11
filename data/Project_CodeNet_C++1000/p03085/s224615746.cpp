#include <bits/stdc++.h>
#include <vector>
# include <cstdint>
#define FOR(i,l,r) for(int i=(l);i<(r);++i)
#define RFOR(i,l,r) for(int i=(l);i>=(int)(r);i--)
#define rep(i,n)  FOR(i,0,n)
#define rrep(i,n)  RFOR(i,n-1,0)

using namespace std;
#define int long long
using ll = long long;
const int MX = 1e6;
const ll inf = 1e13;
const int mod = 1e9+7;

signed main() {
    string s;
    cin >> s;
    rep(i,s.length()) {
        char c = s[i];
        if(c=='A') {
            cout << "T" << flush;
        }else if(c=='T') {
        cout << "A" << flush;
            
        }else if(c=='C') {
            cout << "G" << flush;
        
        }else {
            cout << "C" << flush;
        
        }
        cout << "" << endl;
    }

    return 0;
}

