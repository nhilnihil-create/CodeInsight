#include <iostream>
#include<bits/stdc++.h>
using namespace std;
#define MAX 100000
int main() {
    int n,k;
    cin >> n >> k;
    vector<int> dp(MAX,0);
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin >> arr[i];
        dp[arr[i]] = 1;
    }
    for(int i=0;i<=k;i++){
        if(!dp[i]){
            for(int j=0;j<n;j++){
                if(i-arr[j]>=0) dp[i] = dp[i] || !dp[i-arr[j]];
            }
        }
    }
    if(dp[k]) cout << "First" << endl;
    else cout << "Second" << endl;
	return 0;
}