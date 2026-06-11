#include <iostream>

int main(){
    int n, k;
    std::cin >> n >> k;

    int count = n / 2;
    if(0 != n % 2){
        ++count;
    }

    std::string ans = "NO";
    if(k <= count){
        ans = "YES";
    }

    std::cout << ans << std::endl;

    return 0;
}