#include <iostream>

int main() {
    int cnta = 0, cntb = 0, cntab = 0, cntba = 0;

    int n; std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::string s; std::cin >> s;

        for (size_t j = 0; j < s.size() - 1; j++) {
            if (s[j] == 'A' && s[j+1] == 'B') {
                cntab++;
            }
        }
        if (s[0] == 'B' && s[s.size()-1] == 'A') {
            cntba++;
        } else if (s[0] == 'B') {
            cntb++;
        } else if (s[s.size()-1] == 'A') {
            cnta++;
        }
    }

    if (cntba == 0) {
        cntab += std::min(cnta, cntb);
    } else {
        if (cnta == 0 && cntb == 0) {
            cntab += cntba - 1;
        } else {
            cntab += (cntba + std::min(cnta, cntb));
        }
    }

    std::cout << cntab << std::endl;
    return 0;
}