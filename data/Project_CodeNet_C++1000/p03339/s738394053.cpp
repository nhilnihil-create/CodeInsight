#include <iostream>
#include <vector>

int main() {
    int n; std::string s; std::cin >> n >> s;
    int e = 0, w = 0;
    for (auto c: s) {
        if (c == 'E') {
            e++;
        }
    }

    int m = n;

    for (int i = 0; i < n; i++) {
        if (s[i] == 'E') {
            e--;
            m = std::min(m, w + e);
        } else {
            m = std::min(m, w + e);
            w++;
        }
    }
    std::cout << m << std::endl;
    return 0;
}