#include <iostream>

int main(){
    int n, a, b; 
    std::cin >> n >> a >> b;

    std::cout << std::min(a, b) << " " << std::max(0, a + b - n) << std::endl;

    return 0;
}