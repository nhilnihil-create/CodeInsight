#include <iostream>

int main(void){
    int a, b, c, ans=0;
    std::cin >> a >> b >> c;
    for (int i = 0; i < 2; ++i){
        if (a < b){
            int tmp = a;
            a = b;
            b = tmp;
        }
        if (b < c){
            int tmp = b;
            b = c;
            c = tmp;
        }
    }

    int d1 = a - b;
    int d2 = a - c;
    ans += d1;
    d2 -= d1;
    if (d2 % 2 == 0){
        ans += d2 / 2;
    } else {
        ans += d2 / 2 + 2;
    }

    std::cout << ans << std::endl;

    return 0;
}
