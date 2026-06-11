#include <iostream>
#include <map>

int main()
{
    std::map<int, int> s;
    for (int i = 0; i < 6; i++) {
        int a; std::cin >> a;
        s[a]++;
    }
    bool b = true;
    for (const auto& ss: s) {
        if (ss.second >= 3) {
            b = false;
        }
    }
    std::cout << (b?"YES":"NO") << std::endl;
    return 0;
}
