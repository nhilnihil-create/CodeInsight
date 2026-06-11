#include <iostream>
#include <bits/stdc++.h>
using namespace std;

string solve(int *arr, int n, int k){
    bool dp[k+1];
    memset(dp, 0, sizeof dp);

    for(int i=1;i<=k;i++){
        for(int j=0;j<n;j++){
            if(arr[j] > i){
                continue;
            }
            if(dp[i-arr[j]]==0){
                dp[i] = 1; 
            }
        }
        
    }

    return dp[k] ? "First" : "Second"; 
}

int main() {
    int n, k;
    cin >> n >> k;
    int *arr = new int[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    cout << solve(arr, n, k) <<endl;
}
