#include <iostream>
using namespace std;
#define ll long long
ll mod = 1000000007;
ll dp[1<<21];
int main(){
    int n; cin >> n;
    int a[n][n];
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin >> a[i][j];
    dp[0] = 1;
    for(int i=1;i<1<<n;++i){
        int cnt = 0;
        for(int j=0;j<n;j++)
            if((1<<j)&i) ++cnt;
        for(int j=0;j<n;j++){
            if((1<<j)&i && a[cnt-1][j]){
                dp[i]+=dp[i^(1<<j)];
            }
        }
        dp[i]%=mod;
    }
    if(dp[(1<<n)-1]<0) dp[(1<<n)-1]+=mod;
    cout << dp[(1<<n)-1];
}
