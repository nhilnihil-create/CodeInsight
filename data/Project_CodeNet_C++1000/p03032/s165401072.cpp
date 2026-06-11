#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int maxN= 50;
const ll INF =ll(1e18)+5;
ll dp[maxN][maxN][maxN];
ll V[maxN];
ll N,K;

ll dfs(int l,int r,int stay){
    if(l>N-1-r || l+r+stay ==K){
        //  cerr <<"l="<<l <<"r="<<r <<"stay=" << stay << ", 0 value"  << endl;
        return 0;
    }
    if(l +r + stay>K){
        return -INF;
    }
   
    if(dp[l][r][stay] != -1){
        return dp[l][r][stay];
    }
    ll temp;
    temp = max(dfs(l+1,r,stay) + V[l],dfs(l,r+1,stay) + V[N-1-r]);
    if(l+r+stay+1<K){
        temp = max(temp,dfs(l+1,r,stay+1));
        temp = max(temp,dfs(l,r+1,stay+1));
    }
    temp = max(temp,0LL);
    dp[l][r][stay] =temp;
    // cerr <<"l="<<l <<"r="<<r <<"stay=" << stay << "val=" << dp[l][r][stay] << endl;
    return dp[l][r][stay];
}

int main() {
    cin >> N >>K;
    for(int i=0;i<N;i++){
        cin >> V[i];
    }
    memset(dp,-1,sizeof(dp));
    dfs(0,0,0);
    cout << dp[0][0][0] << endl;
    return 0;
}