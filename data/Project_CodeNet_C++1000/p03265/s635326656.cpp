#include <iostream>

int main(void){
    int x1, y1, x2, y2, dx, dy;
    std::cin >> x1 >> y1 >> x2 >> y2;
    dx = x2 - x1;
    dy = y2 - y1;
    std::cout << x2 - dy << " " \
              << y2 + dx << " " \
              << x1 - dy << " " \
              << y1 + dx << std::endl;

    return 0;
}
