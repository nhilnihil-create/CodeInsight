#include <iostream>
#include <math.h>

int main() {
    int n;
    std::cin >> n;
    if (n < 105) {
        std::cout << 0 << std::endl;
        return 0;
    }
    int num = 1;
    for (int k = 107; k <= n; k+=2) {
        int sk = sqrt((double) k);
        if (k == sk*sk) {
            continue;
        }
        int cnt = 1;
        for(int i = 3; i <= sk; i+=2) {
            if (k%i == 0) cnt++;
            if (cnt > 4) {
                break;
            }
        }
        if (cnt == 4) {
            num++;
        }
    }
    std::cout << num << std::endl;
    return 0;
}