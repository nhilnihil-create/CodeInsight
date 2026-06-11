#include <iostream>

int main(){
    int A, B, T, ans = 0;
    std::cin >> A >> B >> T;

    for(auto i = A; i <= T; i += A){
        ans += B;
    }

    std::cout << ans << std::endl;

    return 0;
}
