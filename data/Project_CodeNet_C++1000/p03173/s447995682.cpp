#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e18+10;
const int mod = 1e9+7;
const int N = 401;
using ll = long long;
ll n,dp[N][N], arr[N], cum[N];
void add_self(int &a, int b) {
    a = (a + b) % mod;
    if(a < 0) a += mod;
}
ll f(int i, int j) {
    return cum[j]-cum[i-1] + dp[i][j];
}

map<pair<int, int>,int> M;
int main()
{
    scanf("%lld", &n);
    for(int i =1; i <= n; i++) scanf("%lld", &arr[i]);
    for(int i = 1; i <= n; i++) cum[i] = cum[i-1] + arr[i];
    for(int i =1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            dp[i][j]=inf;
        }
    }
    for(int sz = 1; sz <= n; sz++) {
        for(int i = 1; i <= n; i++) {
            int j = i+sz-1;
            if(j > n) break;
            if(sz==1) dp[i][j]=0;
            else {
                for(int k = i; k < j; k++) {
                    dp[i][j] = min(dp[i][j], f(i, k) + f(k+1, j));
                    //dp[i][j] = min(dp[i][j], f(i, k)+f(k+1,j));
                }
            }
        }
    }
    printf("%lld\n", dp[1][n]);
    return 0;
}

//dp[2][1] += (dp[1][2])