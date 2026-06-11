#include <iostream>

int main(void){
    int tmp=0, ans=0;

    for (int i=0; i<5; ++i){
        int N, rem;
        std::cin >> N;
        rem = -(N % 10);
        if (rem != 0) rem += 10;
        if (tmp < rem) tmp = rem;
        ans += N + rem;
    }

    ans -= tmp;

    std::cout << ans << std::endl;

    return 0;
}
