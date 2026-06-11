#include <iostream>
int main() {
    int a[4], k; std::cin >> a[0] >> a[1] >> a[2] >> k;
    int n = 0;
    for (int i = 1 ; i < 3; i++){
        if (a[n] < a[i]) {
            n = i;
        }
    }

    for (int i = 0; i < k; i++) {
        a[n] *= 2;
    }

    std::cout << (a[0] + a[1] + a[2]) << std::endl;
    return 0;
}