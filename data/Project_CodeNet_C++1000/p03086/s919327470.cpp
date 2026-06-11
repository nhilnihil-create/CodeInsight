#include <iostream>
#include <string>

int main() {
    std::string S;
    std::cin >> S;
    int n = S.length();

    int l = 0, maxl = 0;
    for (int i = 0; i < n; ++i) {
        if (S[i] == 'A' || S[i] == 'T' || S[i] == 'G' || S[i] == 'C'){
            ++l;
        } else {
            maxl = std::max(maxl, l);
            l = 0;
        }
    }
    std::cout << std::max(maxl, l) << '\n';
}