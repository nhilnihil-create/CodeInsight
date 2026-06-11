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

int rec(int i, int j){
    if(dp[i][j]>0) return dp[i][j];
    if(i==0) return 0;
    
    int r = 0;
    rep(k, 3){
        if(i==1 || j!=k)chmax(r, rec(i-1, k) + v[i-1][k]);
    }

    return dp[i][j] = r;
}

int main(){
    int N;
    cin >> N;
    
    rep(i, N) rep(j, 3) cin >> v[i][j];

    cout << max({rec(N, 0), rec(N, 1), rec(N, 2)}) << endl;
    return 0;
}
