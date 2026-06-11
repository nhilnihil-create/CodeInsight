#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; ++i)
using namespace std;
using ll = int64_t;
using vi = vector<int>;
using vvi = vector<vi>;

vvi dp;
int n, m;
vi a;
vi vec = {0, 2, 5, 5, 4, 5, 6, 3, 7, 6};
string S;

void dfs(int i_, int j_) {
    int i = m-i_;
    int j = n-j_;
    if(!i) {
        return;
    }
    if(j-vec[a[i-1]]>=0 && dp[i][j]-1 == dp[i][j-vec[a[i-1]]]) {
        S += '0' + a[i-1];
        dfs(i_, j_+vec[a[i-1]]);
        return;
    }
    dfs(i_+1, j_);
}



int main() {
    
    cin >> n >> m;
    a.resize(m);
    rep(i, m) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    
    dp.assign(m+1, vi(n+1, -1));
    dp[0][0] = 0;
    rep(i, m) {
        rep(j, n+1) {
            int k=0;
            if(!j || dp[i][j] != -1) {
                while(j + k*vec[a[i]] <= n) {
                    dp[i+1][j+k*vec[a[i]]] = max(dp[i][j]+k, dp[i+1][j+k*vec[a[i]]]);

                    ++k;
                }
            }
        }
    }
    dfs(0, 0);

    /*rep(i, m+1) {
        rep(j, n+1) {
            cout << dp[i][j] << ' ';
        }
        cout << endl;
    }*/

    cout << S << endl;
    
}