#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9;
const int mod = 1e9+7;
const int N = 101;
using ll = long long;
int n, K,dp[100001];
void add_self(int &a, int b) {
    a = (a + b) % mod;
    if(a < 0) a += mod;
}
int main()
{
    scanf("%d %d", &n, &K);
    dp[0]=1;
    for(int i = 1; i <= n; i++) {
        vector<int> fake(K+1, 0);
        int x;
        scanf("%d", &x);
        for(int k = K; k >= 0; k--) {
            int L = k+1, R = k+min(x, K-k);
            if(L <= K)add_self(fake[L], dp[k]);
            if(R+1 <= K) add_self(fake[R+1], -dp[k]);
        }
        int now = 0;
        for(int k = 1; k <= K; k++) {
            add_self(now, fake[k]);
            add_self(dp[k], now);
        }
    }
    printf("%d\n", dp[K]%mod);
    return 0;
}

//dp[2][1] += (dp[1][2])