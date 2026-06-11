//----------------------------------------------------------------------
#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
//----------------------------------------------------------------------

using namespace std;
using ll = long long;
using P = pair<int,int>;
using Graph = vector<vector<int>>;

int main(void) {
    int n, m;
    cin >> n >> m;
    Graph denkyu(m);
    vector<int> onofflag(m);
    rep(i, m) {
        int k;
        cin >> k;
        denkyu[i].resize(k);
        rep(j, k) cin >> denkyu[i][j];
    }
    rep(i,m) cin >> onofflag[i];

    int ans = 0;
    for(int bit = 0; bit < (1 << n); ++bit) {
        int lightnum = 0;
        for(int i = 0; i < m; ++i) {
            int num = 0;
            for(auto v : denkyu[i]) {
                if(bit & (1 << (v - 1))) {
                    num++;
                }
            }
            if(num % 2 == onofflag[i]) {
                lightnum++;
            }
        }
        if(lightnum == m) ans++;
    }

    cout << ans << endl;
    return 0;
}
