#include <bits/stdc++.h>

#define int long long

using namespace std;


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);


    int n, k;
    cin >> n >> k;
    vector<int> dp(k + 1, -1);
    vector<int> x(n);
    for(int i = 0; i < n; i++){
        cin >> x[i];
        dp[x[i]] = 1;
    }
    for(int i = 0; i < x[0]; i++){
        dp[i] = 2;
    }   
    for(int val = 0; val <= k; val++){
        if(dp[val] == -1){
            bool ok = false;
            for(int i = 0; i < n; i++){
                if(val - x[i] >= 0){
                    if(dp[val - x[i]] == 2){
                        ok = true;
                        break;
                    }
                }
            }
            if(ok) dp[val] = 1;
            else dp[val] = 2;
        }
    }

    int cnt = 0;

    while (k >= x[0]){
        if(dp[k] == 1){
            for(int i = 0; i < n; i++){
                if(k - x[i] >= 0){
                    if(dp[k - x[i]] == 2){
                        k -= x[i];
                        break;
                    }
                }
            }
        }
        else{
            k -= x[0];
        }
        cnt++;
    }
    cout << (cnt % 2 == 1 ? "First" : "Second");
    return 0;
}