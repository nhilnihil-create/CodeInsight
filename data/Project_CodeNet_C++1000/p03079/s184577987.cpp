#include <iostream>

int main() {

    int A, B, C;
    std::cin >> A >> B >> C;

    std::cout << (A == B && A == C ? "Yes" : "No") << std::endl;

    return 0;

}
