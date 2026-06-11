#include <map>
#include <iostream>
using namespace std;
int main() {
    string s; cin >> s;
    const int n = s.size();
    int f[n+1];
    map<int, int> g;
    int dp[n+1];
    f[0] = 0;
    g[0] = 0;
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        f[i] = f[i-1]^(1<<(s[i-1]-'a'));
        int val = i;
        for (int j = 0; j < 26; j++) {
            int b = f[i]^(1<<j);
            if (g.find(b) != g.end())
                val = min(val, 1 + g[b]);
        }
        if (g.find(f[i]) != g.end()) {
            val = min(val, 1 + g[f[i]]);
            g[f[i]] = min(g[f[i]], val);
        } else
            g[f[i]] = val;
        dp[i] = val;
    }
    cout << dp[n] << endl;
}
