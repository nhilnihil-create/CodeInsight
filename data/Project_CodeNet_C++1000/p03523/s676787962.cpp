#include <algorithm>
#include <iostream>
#include <vector>

int main()
{
    std::string s;
    std::cin >> s;

    std::string akiba = "AKIHABARA";

    if (s.length() > akiba.length()) {
        std::cout << "NO" << std::endl;
        return 0;
    }

    int ptr_akiba = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] != akiba[ptr_akiba]) {
            if (akiba[ptr_akiba] != 'A') {
                std::cout << "NO" << std::endl;
                return 0;
            }
            i--;
        }
        ptr_akiba++;
    }

    if (ptr_akiba < akiba.length() - 1) {
        std::cout << "NO" << std::endl;
        return 0;
    }

    std::cout << "YES" << std::endl;
}
