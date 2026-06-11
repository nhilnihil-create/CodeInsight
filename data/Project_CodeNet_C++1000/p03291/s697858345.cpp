#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <utility>
#include <cmath>
#include <vector>
#include <queue>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    string s;
    cin >> s;
    int n = s.size();

    ll dp[100010][4] = {};

    for(int i = n; i >= 0; i--) {
        for(int j = 3; j >= 0; j--) {
            if(i == n) {
                dp[i][j] = (j == 3 ? 1 : 0);
            }
            else {
                dp[i][j] = dp[i+1][j] * (s[i] == '?' ? 3LL : 1LL);
                if(j < 3 && (s[i] == '?' || s[i] == "ABC"[j])) {
                    dp[i][j] += dp[i+1][j+1];
                }
                dp[i][j] %= mod;
            }
        }
    }
    
    cout << dp[0][0] << endl;
    return 0;
}