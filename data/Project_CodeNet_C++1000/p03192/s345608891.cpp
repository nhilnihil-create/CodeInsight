#include <algorithm>
#include <iostream>

int main()
{
    std::string s;
    std::cin >> s;

    std::cout << std::count(s.begin(), s.end(), '2') << std::endl;
}
