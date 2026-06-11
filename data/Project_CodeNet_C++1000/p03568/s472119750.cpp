#include <iostream>
#include <cmath>

int main(void){
    int N, o = 0, e = 0, ans = 0;
    std::cin >> N;
    for (int i = 0; i < N; ++i){
        int a;
        std::cin >> a;
        if (a % 2 == 0) ++e;
        else ++o;
    }

    ans = std::pow(3, N) - std::pow(1, o) * std::pow(2, e);

    std::cout << ans << std::endl;

    return 0;
}
