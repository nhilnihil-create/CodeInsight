#include <iostream>
int main() {
    std::string s; std::cin >> s;
    int pre = (s[0] - '0') * 10 + s[1] - '0';
    int sec = (s[2] - '0') * 10 + s[3] - '0';
    bool pp = 0 < pre && pre < 13;
    bool ss = 0 < sec && sec < 13;
    if (pp && !ss) {
        std::cout << "MMYY" << std::endl;
    } else if (!pp && ss) {
        std::cout << "YYMM" << std::endl;
    } else if (pp && ss) {
        std::cout << "AMBIGUOUS" << std::endl;
    } else {
        std::cout << "NA" << std::endl;
    }
    return 0;
}