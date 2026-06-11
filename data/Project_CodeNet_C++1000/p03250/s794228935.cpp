#include<iostream>
#include<algorithm>

int main(){
    int A, B, C;
    std::cin >> A >> B >> C;
    std::cout << std::max({10 * A + B + C, 10 * B + A + C, 10 * C + A + B}) << std::endl;
    return 0;
}
