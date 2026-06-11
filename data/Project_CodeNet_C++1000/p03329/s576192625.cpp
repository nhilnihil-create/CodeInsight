#include <iostream>
#include <vector>
#include <set>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
int n, m, q;
int a[51], b[51], c[51], d[51];
int v[11];
 
int main() {
    int dp[1000000] = {};
    dp[0] = 0;
    int N;
    cin >> N;
    rep(i, 1, 1000000) {
        dp[i] = 1000000;
        int num = 1;
        while (num <= i) {
            dp[i] = min(dp[i], dp[i-num]+1);
            num *= 6;
        }
        num = 1;
        while (num <= i) {
            dp[i] = min(dp[i], dp[i-num]+1);
            num *= 9;
        }
    }
    cout << dp[N] << endl;
    return 0;
}
