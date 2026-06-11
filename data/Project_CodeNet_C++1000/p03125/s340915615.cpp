#include <iostream>

int main(){
    int A, B;
    std::cin >> A >> B;
    
    int ans = B % A == 0 ? (A + B) : (B - A);

    std::cout << ans << std::endl;

    return 0;
}
