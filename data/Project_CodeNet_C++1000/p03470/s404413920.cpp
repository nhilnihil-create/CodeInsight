/*
  Contest 085
  B - Kagami Mochi
  Rakesh Kumar --> 17/09/2020
 */

#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0); std::cout.tie(0);

    int n = 0;
    std::cin >> n;
    std::set<int> chaawal_ka_stupa;
    while (n--) {
        int e = 0;
        std::cin >> e;
        chaawal_ka_stupa.insert(e);
    }
    std::cout << chaawal_ka_stupa.size() << std::endl;

    return 0;
}
