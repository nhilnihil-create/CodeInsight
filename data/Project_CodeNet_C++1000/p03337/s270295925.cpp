#include<iostream>
#include<algorithm>

int main(){
    int A, B;
    std::cin >> A >> B;
    std::cout << std::max({A + B, A - B, A * B}) << std::endl;
    return 0;
}
