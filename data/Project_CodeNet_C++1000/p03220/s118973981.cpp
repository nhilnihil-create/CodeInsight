#include <iostream>
#include <cmath>

int main(void){
    int N, ans=0;
    double dT=1000.0, T, A;
    std::cin >> N >> T >> A;

    for (int i=0; i<N; ++i){
        double h, tmp;
        std::cin >> h;
        tmp = T - 0.006 * h;
        if (dT > std::abs(A - tmp)){
            dT = std::abs(A - tmp);
            ans = i + 1;
        }
    }

    std::cout << ans << std::endl;

    return 0;
}
