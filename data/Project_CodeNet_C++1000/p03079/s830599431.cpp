#include <iostream>

int main(){
    int a, b, c;
    std::cin >> a >> b >> c;

    std::string ans = "No";
    if(a == b && b == c && c == a){
        ans = "Yes";
    }

    std::cout << ans << std::endl;

    return 0;
}