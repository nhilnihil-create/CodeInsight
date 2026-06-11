#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define INF ((1<<30)-1)
#define LINF (1LL<<60)
typedef long long ll;
 
ll dp[1 << 21];
ll n;
ll a[23][23];
ll bitcnt[1<<21];
 
int main(){
    cin >> n;
    for(int i = 0;i < n;i++)
        for(int j = 0;j < n;j++)
            cin >> a[i][j];
 
    dp[0] = 1;
    for(int s = 1;s < (1<<n);s++){
        bitcnt[s] = bitcnt[s/2] + s%2;
        for(int l = 0;l < n;l++){
            if((s >> l) % 2 == 0)continue;
            dp[s] += dp[s - (1 << l)] * a[bitcnt[s] - 1][l];
            dp[s] %= MOD;
        }
    }
    cout << dp[(1 << n) - 1] << endl;    
    return 0;
}