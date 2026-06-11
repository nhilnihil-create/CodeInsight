#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

int main () {
    int n;
    std::string s;
    std::cin >> n >> s;

    int dp[n];
    int kp[n];
    dp[0] = (s[0] == 'W') ? 1 : 0;
    kp[0] = (s[n-1] == 'E') ? 1 : 0;
    for (int i = 0; i < n - 1; i++)
    { 
        if(s[i + 1] == 'W') {
            dp[i + 1] = dp[i] + 1;
        } else {
            dp[i + 1] = dp[i];
        }

        if(s[n - 1 - (i+1)] ==  'E' ) {
            kp[i + 1] = kp[i] + 1;
        } else {
            kp[i + 1] = kp[i];
        }

        
    }

    int min = 400000;
    for (int i = 0; i < n; i++) {
        if(min > dp[i] + kp[n-1-i] - 1) {
            min = dp[i] + kp[n-1-i] - 1;
        }
    }

        std::cout << min << "\n";
}