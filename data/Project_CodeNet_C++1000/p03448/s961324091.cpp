#include <iostream>

int main(void){
    int A, B, C, X, ans=0;
    std::cin >> A >> B >> C >> X;

    for (int i=0; i<=A; ++i){
        for (int j=0; j<=B; ++j){
            for (int k=0; k<=C; ++k){
                if (500 * i + 100 * j + 50 * k == X) ++ans;
            }
        }
    }

    std::cout << ans << std::endl;
    
    return 0;
}
