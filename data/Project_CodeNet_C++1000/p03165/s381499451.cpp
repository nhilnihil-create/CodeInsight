#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
string s, t;
ll dp[3007][3007];

int main() {
    cin >> s >> t;
    s += ';';
    t += '.';

    for(ll i = 0; i < s.length(); ++i) {
        for(ll j = 0; j < t.length(); ++j) {
            if(s[i] == t[j]) dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + 1);
            dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
            dp[i][j+1] = max(dp[i][j], dp[i][j+1]);
        }
    }

    ll i = s.length() - 1, j = t.length() - 1;

    string ans = "";
    while(i && j) {
        ll cur = dp[i][j];
        if(dp[i - 1][j] == cur) i--;
        else if(dp[i][j - 1] == cur) j--;
        else {
            i--;
            j--;
            ans += s[i];
        }
    }

    reverse(ans.begin(), ans.end());
    cout << ans << endl;
    return 0;
}