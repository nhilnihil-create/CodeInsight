#include <iostream>

int main(void){
    int N, ans=0;
    std::cin >> N;

    for(int i=0; i<N; ++i){
        int a;
        std::cin >> a;
        while(a % 2 == 0 && a > 1){
            ++ans;
            a >>= 1; 
        }
    }

    std::cout << ans << std::endl;

    return 0;
}
