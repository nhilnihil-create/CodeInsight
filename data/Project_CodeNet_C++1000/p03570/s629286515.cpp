#include <iostream>
using namespace std;
 
int main() {
    string s;
    cin >> s;
 
    int N = s.size();
 
    static int opt[1 << 26];
    for (int mask = 0; mask < (1 << 26); mask++) opt[mask] = 1 << 28;
 
    opt[0] = 0;
    static int dp[300000];
    int mask = 0;
    for (int i = 0; i < N; i++) {
        mask ^= 1 << (s[i] - 'a');
        dp[i + 1] = opt[mask] + 1;
        for (int j = 0; j < 26; j++) {
            dp[i + 1] = min(dp[i + 1], opt[mask ^ (1 << j)] + 1);
        }
 
        opt[mask] = min(opt[mask], dp[i + 1]);
    }
    cout << dp[N] << endl;
 
    return 0;
}