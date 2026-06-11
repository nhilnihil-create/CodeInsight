#include <iostream>

int main(){
    int a, b;
    std::cin >> a >> b;

    std::string ans = "x";
    if(15 == a + b){
        ans = "+";
    }else if(15 == a * b){
        ans = "*";
    }

    std::cout << ans << std::endl;

    return 0;
}