#include <iostream>

int main(void){
    int N, M, X, a=0, b=0, ans;
    std::cin >> N >> M >> X;
    for (int i=0; i<M; i++){
        int tmp;
        std::cin >> tmp;
        if (tmp < X) {
            ++a;
        } else {
            ++b;
        }
    }

    if (a < b) ans = a;
    else ans = b;

    std::cout << ans << std::endl;

    return 0;
}
