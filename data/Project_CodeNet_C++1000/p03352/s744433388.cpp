#include <iostream>
#include <cmath>

int main(void){
    int X, ans=0;
    std::cin >> X;
    for (int i=1; i<32; ++i){
        for (int j=2; j<10; ++j){
            int x = std::pow(i, j);
            if (x <= X && x > ans){
                ans = x;
            } else if (x > X) break;
        }
    }

    std::cout << ans << std::endl;

    return 0;
}
