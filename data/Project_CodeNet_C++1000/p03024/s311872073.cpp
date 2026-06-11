#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

int main()
{
    std::string s;
    std::cin >> s;
    int win = 0;
    for (char ch : s)
    {
        if (ch == 'o') { win++; }
    }
    for (int i = 0; i < 15 - s.length(); i++) { win++; }
    if (win >= 8) { std::cout << "YES" << std::endl; }
    else
    {
        std::cout << "NO" << std::endl;
    }
    return 0;
}