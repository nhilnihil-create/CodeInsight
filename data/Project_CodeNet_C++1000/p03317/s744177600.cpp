#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <climits>
int main()
{
    long N,K;
    std::cin >> N >> K;
    std::cout << std::ceil((double)(N-1)/(K-1)) << std::endl;
    return 0;
}