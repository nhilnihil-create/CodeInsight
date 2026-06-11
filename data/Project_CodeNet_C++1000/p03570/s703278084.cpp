#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <bitset>
#include <unordered_map>

using ll = long long;

using namespace std;

using bs = bitset<26>;
#define INF 200010

int main() {
    string s;
    cin >> s;
    int len = s.size();
    vector<bs> rui(1, 0);
    for (int i=0; i<len; i++) {
        rui.push_back(rui.back());
        rui.back().flip(s[i] - 'a');
    }
    unordered_map<bs, int> dp;
    dp[0] = 0;
    for (int i=0; i<=len; i++) {
        for (int j=0; j<=26; j++) {
            bs from = rui[i];
            if (j > 0) from = from.flip(j-1);
            if (!dp.count(rui[i])) dp[rui[i]] = INF;
            int cost = (dp.count(from) ? dp[from] : INF);
            dp[rui[i]] = min(dp[rui[i]], cost + 1);
        }
    }
    cout << max(dp[rui[len]], 1) << '\n';
    return 0;
}
