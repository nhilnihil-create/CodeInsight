#include <iostream>
#include <cmath>

int main(void){
    long long D, N, ans=0;
    std::cin >> D >> N;

    ans = std::pow(100, D) * N;

    if (N == 100) ans += std::pow(100, D);

    std::cout << ans << std::endl;

    return 0;
}
