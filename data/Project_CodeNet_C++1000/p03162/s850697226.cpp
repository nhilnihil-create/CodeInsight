#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i <(n); i++)
#define rep2(i,l,r) for (int i=(l); i<(r); i++)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
//~ using P = pair<int, int>;

template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

int v[100100][3];
vector<vector<int>> dp(100100, vector<int>(3, 0));

int main(){
    int N;
    cin >> N;
    
    rep(i, N){
        rep(j, 3){
            cin >> v[i][j];
        }
    }

    dp[0][0] = dp[0][1] = dp[0][2] = 0;
    
    rep(i, N){
        rep(j, 3){
            rep(k, 3){
                if(i==0 || j!=k) chmax(dp[i+1][j], dp[i][k] + v[i][k]);
            }
        }
    }
    
    int ans;
    ans = max({dp[N][0], dp[N][1], dp[N][2]});
    cout << ans << endl;
    return 0;
}
