#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stack>
#include <queue>
#include <map>
#include <unordered_map>
#include <cassert>
using namespace std;

int dp[202020];
unordered_map<int, int> dp2;

int main() {
    string s;
    cin >> s;
    int n = int(s.size());
    
    int x = 0;
    dp2[0] = 0;
    for (int i = 0; i < n; i++) {
        x ^= 1 << (s[i] - 'a');
        int m = 1e9;
        if (dp2.count(x) == 0) {
            dp2[x] = 1e9;
        }
        m = min(m, dp2[x]);
        
        for (int j = 0; j < 26; j++) {
            int xx = x ^ (1 << j);
            if (dp2.count(xx) == 0) dp2[xx] = 1e9;
            m = min(m, dp2[xx]);
        }
        
        dp2[x] = min(dp2[x], m + 1);
        dp[i] = m + 1;
    }
    
    cout << dp[n - 1] << endl;
}
