#include <iostream>
#include <vector>

int main()
{
    int n; std::cin >> n;
    std::vector<std::string> s(n);
    bool b = true;
    for (int i = 0; i < n; i++) {
        std::cin >> s[i];
        if (i != 0) {
            if (s[i-1].back() != s[i].front()) {
                b = false;
            }
        }
        for (int j = 0; j < i; j++) {
            if (s[i] == s[j]) {
                b = false;
            }
        }
    }
    std::cout << (b?"Yes":"No") << std::endl;
    return 0;
}
