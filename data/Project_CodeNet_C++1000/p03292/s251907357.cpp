/*
  Contest 103
  A - Task Scheduling Problem
  Rakesh Kumar --> 27/09/2020
 */

#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0); std::cout.tie(0);

    std::vector<int> v(3, 0);
    std::cin >> v[0] >> v[1] >> v[2];
    std::sort(v.begin(), v.end());
    std::cout << v[2] - v[1] + v[1] - v[0] << std::endl;

    return 0;
}
