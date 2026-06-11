#include <iostream>

int main(void){
    int N, D, X, ans=0;
    std::cin >> N >> D >> X;
    --D;

    for (int i=0; i<N; ++i) {
        int a;
        std::cin >> a;
        ans += D / a + 1;
    }

    ans += X;

    std::cout << ans << std::endl;

    return 0;
}
