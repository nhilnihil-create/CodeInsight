//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; ++i)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using namespace std;
using ll = int64_t;
using P = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;



int main() {
    int d, g;
    cin >>d >> g;
    vi p(d), c(d);
    rep(i, d)  {
        cin >> p[i] >> c[i];
    }

    vvi dp(d+1, vi(d*100+1, -1));
    dp[0][0] = 0;
    rep(i, d) {
        rep(j, d*100+1) {
            if(j >= p[i]) {
                rep(k, p[i]) {
                    if(dp[i][j-k] == -1) continue;
                    dp[i+1][j] = max(dp[i+1][j], dp[i][j-k] + (i+1)*100*k);
                }
                if(dp[i][j-p[i]] != -1) dp[i+1][j] = max(dp[i+1][j], dp[i][j-p[i]] + (i+1)*100*p[i] + c[i]);
            } else {
                rep(k, j+1) {
                    if(dp[i][j-k] == -1) continue;
                    dp[i+1][j] = max(dp[i+1][j], dp[i][j-k] + (i+1)*100*k);
                }
            }
        }
    }

    rep(i, d*100+1) {
        if(dp[d][i] == -1) {
            dp[d][i] =2*1e9;
        }
    }

    vi::iterator itr = lower_bound(all(dp[d]), g);
    cout << distance(dp[d].begin(), itr) << endl;
}