#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int cost1[30], cost2[30], cost3[30];

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, C;
    cin >> n >> C;
    vector<vector<int>> D(C, vector<int>(C)), c(n, vector<int>(n));
    rep(i,C)rep(j,C) cin >> D[i][j];
    rep(i,n)rep(j,n){
        cin >> c[i][j];
        --c[i][j];
    }
    rep(i,C){
        rep(j,n)rep(k,n){
            if((j+k)%3 == 0) cost1[i] += D[c[j][k]][i];
            if((j+k)%3 == 1) cost2[i] += D[c[j][k]][i];
            if((j+k)%3 == 2) cost3[i] += D[c[j][k]][i];
        }
    }
    int ans = 1e9;
    for(int i = 0; i < C; ++i){
        for(int j = 0; j < C; ++j){
            if(i == j) continue;
            for(int k = 0; k < C; ++k){
                if(j == k || i == k) continue;
                chmin(ans, cost1[i] + cost2[j] + cost3[k]);
            }
        }
    }
    cout << ans << endl;
    return 0;
}