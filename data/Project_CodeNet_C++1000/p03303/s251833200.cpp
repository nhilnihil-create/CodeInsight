#include <algorithm>
#include <climits>
#include <cmath>
#include <iostream>
#include <unordered_map>
#include <vector>

const int mod = 1e9 + 7;

int main()
{
    std::string s;
    std::cin >> s;

    int n;
    std::cin >> n;

    for (int i = 0; i < s.length(); i += n) {
        std::cout << s[i];
    }
    putchar('\n');
}
