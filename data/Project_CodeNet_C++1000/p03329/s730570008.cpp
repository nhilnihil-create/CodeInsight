#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int main(){
    long long n;
    cin >> n;

    vector<long long> dp(1e6+1, 0);

    long long a = 1, b = 6, c = 9;

    for(long long i = 1; i <= n; i++){
        if(i >= b*6) b = b*6;
        if(i >= c*9) c = c*9;

        if(i <= 5) dp[i] = i;
        else if(i <= 8) dp[i] = min(dp[i-a] + 1, dp[i-b] + 1);
        else{
            dp[i] = min(dp[i-a]+ 1, dp[i-b]+ 1);
            dp[i] = min(dp[i], dp[i-c]+ 1);
        }

    }

    cout << dp[n] << endl;
    return 0;
}