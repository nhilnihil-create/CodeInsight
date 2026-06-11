#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int N;
    // 6は6乗まで 9は5乗まで -> 12通り
    vector<int> sel(1,1);
    for(int i=1;i<=6;i++) {
        sel.push_back(pow(6,i));
    }
    for(int i=1;i<6;i++) {
        sel.push_back(pow(9,i));
    }

    vector<int> dp(200000,INT_MAX);
    cin >> N;
    dp[0] = 0;
    for(int i=0;i<N;i++) {
        for(int j=0;j<sel.size();j++) {
            dp[i+sel[j]] = min(dp[i+sel[j]], dp[i]+1);
        }
    }
    
    cout << dp[N] << endl;

    return 0;
}
