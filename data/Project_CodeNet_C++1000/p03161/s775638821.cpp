// Author: Sayantanu
#include <bits/stdc++.h>

using namespace std;

#define ll long long int
const int mod = 1e9 + 7;


int main() {
    //code
    int n,k;
    cin>>n>>k;
    vector<int> arr(n);
    for(int i = 0;i<n;i++){
        cin>>arr[i];
    }
    vector<int> dp(n);
    dp[0] = 0;
    for(int i = 1;i<n;i++){
        dp[i] = INT_MAX;
        for(int s = 1;s<=k;s++){
            dp[i] = min(dp[i],abs(arr[i] - arr[max(0,i-s)]) + dp[max(0,i-s)]);
        }

        //dp[i] = min(abs(arr[i] - arr[i-1]) + dp[i-1],abs(arr[i] - arr[max(0,i-2)]) + dp[max(0,i-2)]);
    }

    cout<<dp[n-1]<<endl;
    return 0;
}