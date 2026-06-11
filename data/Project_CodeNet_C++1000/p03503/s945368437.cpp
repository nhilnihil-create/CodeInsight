#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;
int main() {
    int n; cin >> n;
    vector<vector<int>> F(n, vector<int>(10)), P(n, vector<int>(11));
    rep(i, n) {
        rep(j, 10) cin >> F[i][j];
    }
    rep(i, n) {
        rep(j, 11) cin >> P[i][j];
    }
    ll ans = -1e18;
    for(int bit=1;bit<(1<<10);bit++) {
        ll res = 0;
        vector<int> store(n);
        rep(i, 10) {//時間帯
            if((bit>>i)&1) {
                rep(j, n) {//店
                    if(F[j][i]) {
                        store[j]++;
                    }
                }
            }
        }
        rep(i, n) {
            res += P[i][store[i]];
        }
        ans = max(ans, res);
    }
    cout << ans;
}
