#include <iostream>

int main(void){
    long long A, B, C, K, ans;
    std::cin >> A >> B >> C >> K;

    if (K % 2 == 0) ans = A - B;
    else ans = B - A;

    std::cout << ans << std::endl;

    return 0;
}
