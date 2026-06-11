#include <bits/stdc++.h>
using namespace std;
int dp[1 << 26];
int main()
{
    int bit = 0;
    string S;
    
    fill_n(dp, 1 << 26, 1 << 27);
    dp[0] = 0;
    cin >> S;
    for(int i = 0; i < S.size(); i++) {
        bit ^= (1 << (S[i] - 'a'));
        for(int j = 0; j < 26; j++) {
            dp[bit] = min(dp[bit], dp[bit ^ (1 << j)] + 1);
        }
    }

    cout << dp[bit] + (dp[bit] == 0) << endl;
            
    return (0);
}