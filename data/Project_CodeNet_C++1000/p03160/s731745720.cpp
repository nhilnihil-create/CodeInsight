#include<iostream>
#include<vector>
#include<limits>
#include<algorithm>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin >> arr[i];
    vector<int> dp(n, INT32_MAX);
    dp[0] = 0;
    for(int i=0;i<n-1;i++){
        dp[i+1] = min(abs(arr[i] - arr[i+1]) + dp[i], dp[i+1]);
        if(i+2 < n) dp[i+2] = min(abs(arr[i] - arr[i+2]) + dp[i], dp[i+2]);
    }
    cout << dp[n-1] << endl;
    return 0;
}