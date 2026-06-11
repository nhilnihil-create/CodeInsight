#include <iostream>
using namespace std;

#include <vector>
int main(){
    int n;cin >> n;
    vector<int> a(n),b(n),c(n);
    for(int i=0; i<n; i++) cin >> a.at(i) >> b.at(i) >> c.at(i);
    vector<vector<int>> dp(n,vector<int>(3));
    dp[0][0] = a.at(0);
    dp[0][1] = b.at(0);
    dp[0][2] = c.at(0);
    for(int i=1; i<n;i++) {
        dp[i][0] = max(dp[i-1][1],dp[i-1][2])+a.at(i);
        dp[i][1] = max(dp[i-1][0],dp[i-1][2])+b.at(i);
        dp[i][2] = max(dp[i-1][1],dp[i-1][0])+c.at(i);
    }
    printf("%d\n",max(dp[n-1][0],max(dp[n-1][1],dp[n-1][2])));
}