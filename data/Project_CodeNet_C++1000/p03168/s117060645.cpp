#include<iostream>
#include<vector>
#define dd long double
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<dd> arr(n+1);
    for(int i=1;i<=n;i++) cin >> arr[i];
    vector<vector<dd>> dp(n+1, vector<dd>(n+1, 0.0));
    dp[0][0] = 1;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=i;j++){
            if(j==0) dp[i][j] = (1-arr[i])*dp[i-1][0];
            else dp[i][j] = arr[i]*dp[i-1][j-1] + (1-arr[i])*dp[i-1][j];
        }
    }
    dd ans = 0.0;
    for(int i=n/2+1;i<=n;i++) ans+=dp[n][i];
    cout.precision(10);
    cout << ans << endl;
    return 0;
}