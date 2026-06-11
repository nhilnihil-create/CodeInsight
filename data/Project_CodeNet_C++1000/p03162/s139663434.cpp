#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int A[n], B[n], C[n], dp[n][3];
    for(int i = 0; i < n; i++){
        cin >> A[i] >> B[i] >> C[i];
    }
    dp[0][0] = A[0];
    dp[0][1] = B[0];
    dp[0][2] = C[0];
    for(int i = 1; i < n; i++){
        dp[i][0] = A[i] + max(dp[i-1][1], dp[i-1][2]);
        dp[i][1] = B[i] + max(dp[i-1][0], dp[i-1][2]);
        dp[i][2] = C[i] + max(dp[i-1][1], dp[i-1][0]);
    }
    cout << max(dp[n-1][0], max(dp[n-1][1], dp[n-1][2]));
    return 0;
}