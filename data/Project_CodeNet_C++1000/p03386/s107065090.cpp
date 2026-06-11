#include <iostream>

int main(void){
    int A, B, K;
    std::cin >> A >> B >> K;

    for (int i=A; i<=B; ++i){
        if (i < A + K || B - K < i){
            std::cout << i << std::endl;
        }
    }

    return 0;
}
