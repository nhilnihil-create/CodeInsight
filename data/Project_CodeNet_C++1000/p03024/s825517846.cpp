#include <algorithm>
#include <iostream>
#include <vector>

int main()
{
    std::string s;
    std::cin >> s;

    std::cout << (std::count(s.begin(), s.end(), 'x') >= 8 ? "NO" : "YES") << std::endl;
}
