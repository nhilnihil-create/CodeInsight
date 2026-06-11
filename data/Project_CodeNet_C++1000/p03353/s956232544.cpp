#include <bits/stdc++.h>

int main() {
    std::string s;
    int K;
    std::cin >> s >> K;

    std::set<std::string> w;
    for (int i = 0; i < 26; ++i) {
        const char c = 'a' + i;

        for (size_t j = 0; j < s.size(); ++j) {
            if (s[j] == c) {
                for (size_t k = 1; k <= 5; ++k) {
                    if ((j + k) > s.size()) {
                        break;
                    }
                    w.insert(s.substr(j, k));
                }
            }
        }

        if (w.size() >= 5) {
            break;
        }
    }

    int index = 0;
    for (const std::string& str : w) {
        if (index == (K - 1)) {
            std::cout << str << std::endl;
            return 0;
        }

        ++index;
    }

    return 0;
}
