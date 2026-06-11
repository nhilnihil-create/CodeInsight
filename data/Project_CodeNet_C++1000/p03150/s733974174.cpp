#include <iostream>
#include <vector>


int main() {
    std::string s; std::cin >> s;
    const std::string k = "keyence";
    for (size_t i = 0; i <= k.size(); i++) {

        bool f = true;
        for (size_t j = 0; j < i; j++) {
            if (s[j] != k[j]) {
                f = false;
                break;
            }
        }
        if (!f) {
            continue;
        }

        for (size_t j = 0; j < k.size() - i; j++) {
            if (s[s.size() - 1 - j] != k[k.size() - 1 - j]) {
                f = false;
                break;
            }
        }

        if (f) {
            std::cout << "YES" << std::endl;
            return 0;
        }

    }

    std::cout << "NO" << std::endl;
    return 0;
}