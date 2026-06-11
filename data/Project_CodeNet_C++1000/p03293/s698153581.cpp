/*
  Contest 103
  B - String Rotation
  Rakesh Kumar --> 27/09/2020
 */

#include <bits/stdc++.h>

inline void rotate(std::string& s) {
    const char t = s[s.size() - 1];
    for (int i = s.size() - 1; i > 0; --i)
        s[i] = s[i - 1];
    s[0] = t;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0); std::cout.tie(0);

    std::string s;
    std::getline(std::cin, s);
    std::string t;
    std::getline(std::cin, t);
    std::string r = "No";
    if (s.size() == t.size()) {
        if (s == t) {
            r = "Yes";
        } else {
            for (std::size_t i = 1; i < s.size(); ++i) {
                rotate(s);
                if (s == t) {
                    r = "Yes";
                    break;
                }
            }
        }
    }
    std::cout << r << std::endl;


    return 0;
}
