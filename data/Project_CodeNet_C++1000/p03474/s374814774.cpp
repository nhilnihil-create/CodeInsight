#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#define pi 3.14159265358979323846264338327950



int main() {
    int a, b; std::cin >> a >> b;
    std::string s; std::cin >> s;
    bool flag = true;
    for (int i = 0; i < s.size(); i++) {
        if ((s.at(i) == '-' && i != a) || (s.at(i) != '-' && i == a))
            flag = false;
    }
    std::cout << (flag ? "Yes" : "No");
}