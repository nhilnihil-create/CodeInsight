#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>

int main()
{
    long N,K;
    std::cin >> N >> K;
    (N%K==0)? std::cout << 0 << std::endl : std::cout << 1 << std::endl;
    return 0;
}