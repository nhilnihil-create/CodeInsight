#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> dp(100001, 100001);
    dp[0] = 0;
    for (int i = 0; i < 100001; i++){
        if (i != 100000){dp[i+1] = min(dp[i+1], dp[i]+1);}
        for (int j = 6; i+j < 100001; j *= 6){dp[i+j] = min(dp[i+j], dp[i]+1);}
        for (int j = 9; i+j < 100001; j *= 9){dp[i+j] = min(dp[i+j], dp[i]+1);}
    }
    cout << dp[n] << endl;
    return 0;
}