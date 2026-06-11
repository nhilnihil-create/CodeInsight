#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e18+10;
const int mod = 1e9+7;
const int N = 22;
using ll = long long;
int n,dp[N][5000000];
bool arr[N][N];
int add(int a, int b) {
    a = (a + b) % mod;
    if(a < 0) a += mod;
    return a;
}
int lim; 
int check(int i, int mask) {
    if(i == n && mask == lim) return 1;
    if(dp[i][mask] != -1) return dp[i][mask];
    int ans = 0;
    for(int j = 0; j < n; j++) {
        if(arr[i][j] && ((mask & (1 << j))==0)) {
            ans = (ans + check(i+1, mask | (1 << j))) % mod;
        }
    }
    return dp[i][mask] = ans;
}
int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) scanf("%d", &arr[i][j]);
    }
    lim = (1<<n) -1;
    memset(dp, -1, sizeof(dp));
    dp[n][lim] = 1;
    /*for(int i = n-1; i >= 0; i--) {
        for(int mask = 0; mask <= lim; mask++) {
            for(int j = 0; j < n; j++) {
                if(arr[i][j] && ((mask & (1 << j)) == 0)) {    //brackets?
                    dp[i][mask] = (dp[i][mask] + dp[i+1][mask | (1 << j)]) % mod;
                }
            }
        }
    }*/
    for(int i = 0;0 && i <= n; i++) {
        for(int j = 0; j <= lim; j++) {
            printf("%d ", dp[i][j]);
        }
        printf("\n");
    }
    cout << check(0, 0);
    //printf("%d\n", dp[0][0]);
    return 0;
}

//dp[2][1] += (dp[1][2])

/*

  0 1 2 3 4 5 6 7           
---------------             0 -> 000
0.3 0 0 0 0 0 0 0           1 -> 001
1.0 1 2 0 1 0 0 0           2 -> 010
2.0 0 0 1 0 1 1 0           3 -> 011
3.0 0 0 0 0 0 0 1           4 -> 100
                            5 -> 101
                            6 -> 110
                            7 -> 111



*/