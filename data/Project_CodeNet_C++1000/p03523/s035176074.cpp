#include <bits/stdc++.h>
using namespace std;
#define rep(i, m, n) for (int i = m; i < n; ++i)

int main() {
    string S; cin >> S;
    string T = "AKIHABARA";
    rep(a, 0, 2) rep(b, 0, 2) rep(c, 0, 2) rep(d, 0, 2) {
        string tmp;
        rep(i, 0, T.size()) {
            if(a && i == 0) continue;
            if(b && i == 4) continue;
            if(c && i == 6) continue;
            if(d && i == 8) continue;
            tmp += T[i];
        }
        if(tmp == S) {
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}
