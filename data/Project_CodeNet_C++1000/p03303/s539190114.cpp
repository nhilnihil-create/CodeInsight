#include <iostream>
#include <string>
int main() {
    std::string s;
    int w;
    std::cin >> s >> w;
    for (int i = 0; i < s.length(); i += w) {
        std::cout << s[i];
    }
    std::cout << '\n';
}