#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;

int main(void) {   
    int n, T;
    cin >> n >> T;
    vector<int> c(n), t(n);
    rep(i, n) cin >> c[i] >> t[i];

    int ans = 1e9;
    rep(i, n) {
        if(t[i] <= T) {
            ans = min(ans, c[i]);
        }
    }

    if(ans == 1e9) puts("TLE");
    else cout << ans << endl;
    return 0;
}