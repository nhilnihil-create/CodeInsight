#include <iostream>
#include <string>

int main()
{
    std::string str;
    std::cin >> str;
    long long sum = 0, i = 0,j=0;
    for (auto&& c : str) {
        if (c == 'W') {
          	sum += (i-j);
          	j++;
        }
        i++;
    }
    std::cout << sum << "\n";
    return 0;
}