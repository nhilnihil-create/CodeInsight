#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::string S;
    std::cin >> S;

    int K;
    std::cin >> K;

    std::vector<std::string> memo;
    for (int i = 0; i < S.length(); i++) {
        for (int d = 1; d <= std::min(K, (int)S.length() - i); d++) {
            memo.emplace_back(S.substr(i, d));
        }
    }

    std::sort(memo.begin(), memo.end());
    memo.erase(std::unique(memo.begin(), memo.end()), memo.end());

    std::cout << memo[K - 1] << '\n';
}