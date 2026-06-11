#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i = 0; i < int(n);i++)

ll dp[62][2];

int main(){
    int n;
    ll K;
    cin >> n >> K;
    vector<ll> v(n);
    rep(i,n) cin >> v[i];

    rep(i,62) rep(j,2) dp[i][j] = -1;

    ll res = 0;
    dp[0][0] = 0;
    rep(i,60) rep(j,2){
        ll mask = 1LL <<(60-i-1);

        int num = 0;
        rep(h,n) if (v[h] & mask) num++;

        ll cost0 = mask * num;
        ll cost1 = mask * (n-num);

        if (dp[i][1] != -1){
            dp[i+1][1] = max(dp[i+1][1],dp[i][1]+max(cost0,cost1));
        }
        if (dp[i][0] != -1){
            if (K & mask){
                dp[i+1][1] = max(dp[i+1][1],dp[i][0]+cost0);
            }
        }
        if (dp[i][0] != -1){
            if (K & mask){
                dp[i+1][0] = max(dp[i+1][0],dp[i][0] + cost1);
            }
            else dp[i+1][0] = max(dp[i+1][0],dp[i][0] + cost0);
        }
    }
    cout << max(dp[60][0],dp[60][1]) << endl;

    
    
    
    return 0;

}
