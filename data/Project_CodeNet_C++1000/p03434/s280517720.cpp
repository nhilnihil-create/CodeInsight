/*
  Contest 088
  A - Infinite Coins
  Rakesh Kumar --> 18/09/2020
 */

#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0); std::cout.tie(0);
    int n = 0;
    std::cin >> n;

    std::vector<int> cards;
    while (n--) {
        int s = 0;
        std::cin >> s;
        cards.emplace_back(s);
    }
    std::sort(cards.rbegin(), cards.rend());

    int alice = 0, bob = 0;
    for (std::size_t i = 0; i < cards.size(); ++i) {
        if (i & 1)
            bob += cards[i];
        else
            alice += cards[i];
    }
    std::cout << alice - bob << std::endl;

    return 0;
}
