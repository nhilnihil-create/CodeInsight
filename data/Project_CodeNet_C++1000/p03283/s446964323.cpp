#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const ll MAX_N =500;
ll N,M,Q;
ll dp[MAX_N][MAX_N];
ll LR[MAX_N][MAX_N];

ll dfs(int l,int r){
    if(l>r){
        return 0;
    }
    if(dp[l][r] != -1){
        return dp[l][r];
    }
    dp[l][r] = dfs(l+1,r) + dfs(l,r-1) -(dfs(l+1,r-1)) + LR[l][r];
    return dp[l][r]; 
}

int main() {
    memset(dp, -1,sizeof(dp));
    memset(LR,0,sizeof(LR));
    cin >> N >>M >>Q;
    for(int i=0;i<M;i++){
        ll l,r;
        cin >> l >> r;
        --l;--r;
        LR[l][r]++;
    }
    dfs(0,N-1);
    for(int i=0;i<Q;i++){
        ll p,q;
        cin >> p >> q;
        --p;--q;
        cout << dp[p][q] << endl;
    }

    return 0;
}