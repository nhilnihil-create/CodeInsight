#include <bits/stdc++.h>
using namespace std;
long double dp[302][302][302];
int n, a = 0, b = 0, c = 0;
long double solve(int i, int j, int k) {
    if(i<0 || j<0 || k<0) return 0;
    if(dp[i][j][k] != -1) return dp[i][j][k];
    dp[i][j][k] = 1 + (i+j+k > 1 ? solve(i-1, j, k)*i/(i+j+k-1.0) : 0) + (i+j+k > 0 ? solve(i+1, j-1, k)*j*1.0/(i+j+k) + solve(i, j+1, k-1)*k*1.0/(i+j+k) : 0);
    return dp[i][j][k];
}
int main() {
    int i, j, k;
    for(i=0;i<302;++i) for(j=0;j<302;++j) for(k=0;k<302;++k) dp[i][j][k] = -1;
    dp[0][0][0] = 0;
    cin >> n;
    for(i = 0; i < n; ++i) {
        cin >> j;
        a += j==1;
        b += j==2;
        c += j==3;
    }
    printf("%0.15Lf", solve(a, b, c));
    return 0;
}