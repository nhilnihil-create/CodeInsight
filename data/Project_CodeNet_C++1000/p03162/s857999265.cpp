#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<vector<int>> arr(n, vector<int>(3));
    for(int i=0;i<n;i++){cin >> arr[i][0] >> arr[i][1] >> arr[i][2];}
    vector<int> dp(3);
    dp[0] = arr[0][0]; dp[1] = arr[0][1]; dp[2] = arr[0][2];
    for(int i=1;i<n;i++){
        int first = dp[0], second = dp[1], third = dp[2];
        dp[0] = max(second+arr[i][0], third+arr[i][0]);
        dp[1] = max(first+arr[i][1], third+arr[i][1]);
        dp[2] = max(first+arr[i][2], second+arr[i][2]);
    }
    cout << max(dp[0], max(dp[1], dp[2])) << endl;
    return 0;
}