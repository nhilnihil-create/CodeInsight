#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)

int main() {
    int N; cin >> N;
    int T; cin >> T;
    int ans = 1000000;
    rep(i, N) {
        int c, t; cin >> c >> t;
        if (T >= t) ans = min(ans, c);
    }
    if (ans == 1000000) cout << "TLE" << endl;
    else cout << ans << endl;
    return 0;
}