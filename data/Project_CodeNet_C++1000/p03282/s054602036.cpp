#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <map>

int main(){
    std::string s; std::cin >> s;
    int K; std::cin >> K;
    for (int i = 0; i < K; ++i) {
        if (s[i] != '1') {
            std::cout << s[i] - '0' << std::endl;
            return 0;
        }
    }
    std::cout << 1 << std::endl;
    return 0;
}