#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.sync_with_stdio(false);
    
    int n, k; cin >> n >> k;
    vector<int>v(n);
    int mini = INT_MAX;
    for(int i = 0; i < n; i++){
        cin >> v[i];
        mini = min(mini, v[i]);
    }

    vector<vector<bool>>dp(k+1, vector<bool>(2, false));
    for(int i = 0; i < mini; i++){
        dp[i][0] = false;
        dp[i][1] = true;
    }

    for(int i = mini; i <= k; i++){
        for(int j = 0; j < n; j++){
            if(i-v[j]>=0){
                dp[i][0] = dp[i][0] | dp[i-v[j]][1];
            }
        }

        dp[i][1] = true;
        for(int j = 0; j < n; j++){
            if(i-v[j]>=0){
                dp[i][1] = dp[i][1] & dp[i-v[j]][0];
            }
        }
    }

    if(dp[k][0]){
        cout<<"First";
    }else{
        cout<<"Second";
    }
}
