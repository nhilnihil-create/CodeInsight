#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
ll arr[101];
ll n, k;
ll dp[101][100001];
ll pre[101][100001];
int main(){
    cin>>n>>k;
    for(int x=1;x<=n;x++)
        cin>>arr[x];

    dp[0][0] = 1;
    pre[0][0] = 1;
    for(int x = 1;x<=k;x++){
        pre[0][x] = 1;
    }
    for(int x=1;x<=n;x++){
        for(int y=0; y<=k; y++){
            int l = max((ll)0, y-arr[x]);
            int r = y;

            //cout<<l << " "<<r<<endl;

            int sub = 0;
            if(l != 0) sub = pre[x-1][l-1];

            dp[x][y] += pre[x-1][r] - sub;
            dp[x][y] %= mod;

//            int dl, dr;
//            for(int z=0;z<=min(arr[x],(ll) y);z++){
//
//            }
        }
        pre[x][0] = 1;
        for(int y=1;y<=k;y++){
            pre[x][y] += dp[x][y]+pre[x][y-1];
            pre[x][y] %= mod;
        }
    }

//    for(int x=0;x<=n;x++){
//        for(int y=0;y<=k;y++){
//            cout<<dp[x][y]<<"  ";
//        }
//        cout<<endl;
//    }
    cout<<(dp[n][k] % mod + mod ) % mod;
}
