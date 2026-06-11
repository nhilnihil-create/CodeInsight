#include <iostream>

bool is_acgt(char c) {
    return c == 'A' || c == 'C' || c == 'G' || c == 'T';
}

int main() {
    std::string s;
    std::cin >> s;

    int max = 0;
    int count = 0;
    bool is_before_acgt = false;
    for (int i = 0; i < s.length(); i++) {
        if (is_acgt(s[i])) {
            count++;
            if (max < count) {
                max = count;
            }
        } else {
            count = 0;
        }
    }

    std::cout << max << std::endl;

    return 0;
}