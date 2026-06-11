
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 3005, M = 1e9 + 7;
int n;
ll dp[N][N];
string s;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> s;
    s = "$" + s;
    dp[0][0] = 1;
    for(int i = 1; i <= n; i++) {
        ll sum = 0;
        for(int v = 0; v <= i; v++) {
            dp[i][v] = sum;
            if(v < i) sum = (sum + dp[i - 1][s[i - 1] == s[i] ? v : i - v - 1]) % M;
        }
    }
    cout << dp[n][n] << endl;
}