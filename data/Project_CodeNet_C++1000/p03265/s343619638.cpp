#include <iostream>

int main(void){
    int x1, y1, x2, y2, dx, dy;
    std::cin >> x1 >> y1 >> x2 >> y2;
    dx = x2 - x1;
    dy = y2 - y1;
    x1 = x2 - dy;
    y1 = y2 + dx;
    std::cout << x1 << " " << y1 << " ";
    dx = x1 - x2;
    dy = y1 - y2;
    x2 = x1 - dy;
    y2 = y1 + dx;
    std::cout << x2 << " " << y2 << std::endl;

    return 0;
}
