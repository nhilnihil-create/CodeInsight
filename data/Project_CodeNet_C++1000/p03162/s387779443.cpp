#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int main(){
    long long n;
    cin >> n;

    vector<long long> a(n+1);
    vector<long long> b(n+1);
    vector<long long> c(n+1);
    for(long long i = 1; i <= n; i++) cin >> a[i] >> b[i] >> c[i];

    vector<vector<long long> > dp(n+1, vector<long long>(3, 0));

    for(long long i = 1; i <= n; i++){
        dp[i][0] = a[i] + max(dp[i-1][1], dp[i-1][2]);
        dp[i][1] = b[i] + max(dp[i-1][2], dp[i-1][0]);
        dp[i][2] = c[i] + max(dp[i-1][0], dp[i-1][1]);
    }

    cout << max(max(dp[n][0], dp[n][1]), dp[n][2]) << endl;
    return 0;
}