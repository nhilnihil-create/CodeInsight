#include "bits/stdc++.h"
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;

typedef long long ll;

int main() {
    string s, t = "";
    cin >> s;
    rep(i, s.size()) {
        if (s.substr(i, 2) == "BC") {
            t.push_back('D');
            i++;
        } else {
            t.push_back(s[i]);
        }
    }
    //cout << t << endl;
    ll ans = 0, a = 0;
    rep(i, t.size()) {
        if (t[i] == 'A') a++;
        else if (t[i] == 'D') ans += a;
        else a = 0;
    }
    cout << ans << endl;
}