#include <bits/stdc++.h>
using namespace std;
int main(){
    int N;
    cin >> N;
    vector<int> a(N),b(N),c(N);
    for(int i=0;i<N;i++) cin >> a.at(i) >> b.at(i) >> c.at(i);

    int dp[3][N];
    dp[0][0] = a.at(0);
    dp[1][0] = b.at(0);
    dp[2][0] = c.at(0);

    for(int i=1;i<N;i++){
        dp[0][i] = max(dp[1][i-1], dp[2][i-1]) + a.at(i);
        dp[1][i] = max(dp[0][i-1], dp[2][i-1]) + b.at(i);
        dp[2][i] = max(dp[0][i-1], dp[1][i-1]) + c.at(i);
    }

    int ans  = max(dp[0][N-1],max(dp[1][N-1],dp[2][N-1]));
    cout << ans << endl;
    return 0;
}