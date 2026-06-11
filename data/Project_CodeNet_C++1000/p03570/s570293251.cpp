#include "bits/stdc++.h"
using namespace std;

static const int INF = 0x3f3f3f3f;

int dp[1 << 26];

int main() {
        string s;
        cin >> s;
        for (int i = 0; i < (1 << 26); i ++) dp[i] = INF;
        dp[0] = 0;
        int a = 0;
        for (int i = 0; i < s.size(); i ++) {
                a ^= (1 << (s[i] - 'a'));
                for (int j = 0; j < 26; j ++) dp[a] = min(dp[a], dp[a ^ (1 << j)] + 1);
        }
        printf("%d\n", dp[a] ? dp[a] : 1);
        return 0;
}
