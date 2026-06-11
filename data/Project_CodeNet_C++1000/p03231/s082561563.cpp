#include <bits/stdc++.h>
typedef long long lint;
using namespace std;
#define rep(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)

lint lcm(lint x, lint y) {
    return abs(x) / __gcd(x,y) * abs(y);
}

void solve() {
    lint n,m; cin >> n >> m;
    string s,t; cin >> s >> t;
    lint l = lcm(n,m);
    map<lint,char> x;
    bool ans = true;
    rep(i,n) {
        // cout << i*(l/n)+1 << ' ';
        x[i*(l/n)+1] = s[i];
    }
    // cout << endl;
    rep(i,m) {
        // cout << i*(l/m)+1 << ' ';
        if (x.count(i*(l/m)+1)) {
            if (x[i*(l/m)+1] != t[i]) ans = false;
        }
    }
    // cout << endl;
    if (ans) cout << l << endl;
    else cout << -1 << endl;
}

int main() {
    solve();
}