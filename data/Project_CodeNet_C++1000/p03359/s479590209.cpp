#include <iostream>
int main() {
    int cnt = 0;
    int a, b; std::cin >> a >> b;
    for (int i = 1; i <= 12; i++) {
        if (i < a) {
            cnt++;
        } else if (i == a) {
            if (i <= b) {
                cnt++;
            }
        }
    }
    std::cout << cnt << std::endl;
    return 0;
}