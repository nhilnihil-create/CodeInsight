#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n';

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int h, w;cin>>h>>w;
    string s[h];
    ll dp[h][w];
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    for(int i = 0; i < h; ++i){
        cin>>s[i];
        for(int j = 0; j < w; ++j){
            if(i) dp[i][j] += dp[i-1][j];
            if(j) dp[i][j] += dp[i][j-1];
            if(s[i][j]=='#') dp[i][j] = 0;
            dp[i][j]%=(ll)1e9 + 7;
        }
    }
    cout<<dp[h-1][w-1]<<endl;
    return 0;

}