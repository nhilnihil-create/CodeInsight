#include <bits/stdc++.h>

using namespace std;
#define ld long double


int main(){
    int n;
    cin >> n;
    ld a[n];
    for(int i = 0; i < n; i++) cin >> a[i];

    ld dp[n+1][n+1];
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1.0;
    
    for(int i = 1; i <= n; i++){
    for(int j = 0; j <= i; j++){
    if(j == 0)
        dp[i][j] = dp[i-1][j] * (1.0 - a[i-1]);
    else{
    dp[i][j] = dp[i-1][j-1] * a[i-1] + dp[i-1][j] * (1.0 - a[i-1]);
}
}
}

ld p = 0.0;
for(int j = 0; j <= n; j++){
    if(j > n/2) p += dp[n][j];
}
cout << setprecision(10) << p;
}


