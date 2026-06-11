#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
#define chmin(x,y) x = min(x,y)

int main(){
    int n,k; cin>>n>>k;
    vector<int> h(n),dp(100005,1e9);
    rep(i,n) cin>>h[i];
    dp[0] = 0;
    rep(i,n)rep(j,k){
            if(i-j>0){
                chmin(dp[i], dp[i-(j+1)]+abs(h[i]-h[i-(j+1)]));
            }
    }
    cout << dp[n-1] << endl;
}