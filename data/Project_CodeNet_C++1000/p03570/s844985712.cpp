#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX_N = 200020;
const int INF = 1<<29;

int dp[1<<26];
int charMask[MAX_N];

int main() {
    ios::sync_with_stdio(false);

    string s;
    cin>>s;

    int currMask = 0;

    for(int i = 0;i<(int)s.size();++i) {
        int bit = s[i]-'a';
        currMask ^= 1<<bit;

        charMask[i] = currMask;
    }

    for(int i = 0;i<(1<<26);++i) {
        dp[i] = INF;
    }

    dp[0] = 0;

    int res = 0;
    for(int i = 0;i<(int)s.size();++i) {
        int best = dp[charMask[i]] != INF ? 1 + dp[charMask[i]] : INF;
        for(int x = 0;x<26;++x) {
            int mask = charMask[i] ^ (1<<x);

            if(dp[mask] != INF) {
                best = min(best, 1+dp[mask]);
            }
        }

        dp[charMask[i]] = min(dp[charMask[i]], best);
        res = best;
    }

    cout<<res<<endl;

    return 0;
}
