#include <bits/stdc++.h>
using i64 = long long;

int main() {
    std::string s;
    std::cin >> s;
    int n = s.size(), b = 0;
    std::vector<int> memo(1 << 26, n);
    memo[0] = 0;
    for (int i = 0; i < n; i++) {
        int index = s[i] - 'a';
        b ^= 1 << index;
        int c = memo[b] + 1;
        for (int j = 0; j < 26; j++) {
            c = std::min(c, memo[b ^ (1 << j)] + 1);
        }
        memo[b] = std::min(memo[b], c);
    }

    int ret = memo[b] + 1;
    for (int i = 0; i < 26; i++) {
        ret = std::min(ret, memo[b ^ (1 << i)] + 1);
    }

    std::cout << ret << std::endl;

    return 0;
}
