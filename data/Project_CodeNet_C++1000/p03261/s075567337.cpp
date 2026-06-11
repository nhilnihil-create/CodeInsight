/*
  Contest 109
  B - Shiritori
  Rakesh Kumar --> 27/09/2020
 */

#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0); std::cout.tie(0);

    int n = 0;
    std::cin >> n;
    std::cin.ignore();
    std::unordered_map<std::string, bool> dict;
    std::string last;
    std::getline(std::cin, last); --n;
    dict[last] = true;
    std::string r = "Yes";
    while (n--) {
        std::string s;
        std::getline(std::cin, s);
        if (dict.find(s) != dict.end())
            r = "No";
        else
            if (s[0] != last[last.size() - 1])
                r = "No";
        dict[s] = true;
        last = s;
    }
    std::cout << r << std::endl;

    return 0;
}
