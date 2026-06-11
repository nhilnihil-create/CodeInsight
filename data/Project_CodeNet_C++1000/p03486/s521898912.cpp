#include <iostream>

int main() {
    std::string s, t;
    std::cin >> s >> t;

    std::sort(s.begin(), s.end());
    std::sort(t.begin(), t.end());
    std::reverse(t.begin(), t.end());
    // std::cout << s << " " << t << " " << (s < t) <<std::endl;
    std::cout <<  ((s < t)?("Yes"):("No")) << std::endl;
    return 0;
}