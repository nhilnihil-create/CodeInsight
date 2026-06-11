#include <iostream>

int main(void){
    long long b = 0, ans = 0;
    std::string S;
    std::cin >> S;

    for (char c: S){
        if (c == 'B'){
            ++b;
        } else {
            ans += b;
        }
    }

    std::cout << ans << std::endl;

    return 0;
}
