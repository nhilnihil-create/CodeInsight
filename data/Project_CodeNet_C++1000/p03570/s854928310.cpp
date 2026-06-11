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
    bs rui[len+1];
    for (int i=0; i<len; i++) {
        rui[i+1] = rui[i];
        rui[i+1].flip(s[i] - 'a');
    }
    unordered_map<bs, int> dp;
    dp[0] = 0;
    for (int i=0; i<=len; i++) {
        for (bs dif('1' + string(25, '0')); ; dif >>= 1) {
            bs from = rui[i] ^ dif;
            if (!dp.count(rui[i])) dp[rui[i]] = INF;
            if (!dp.count(from)) dp[from] = INF;
            dp[rui[i]] = min(dp[rui[i]], dp[from] + 1);
            if (dif.to_ullong() == 0) break;
        }
    }
    cout << max(dp[rui[len]], 1) << '\n';
    return 0;
}