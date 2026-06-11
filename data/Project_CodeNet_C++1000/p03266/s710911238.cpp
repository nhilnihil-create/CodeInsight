#include <iostream>
#include <cmath>

int main(){
    long long n, k;
    std::cin >> n >> k;

    long long ans = 0;
    if(0 == k % 2){
        ans += std::pow(n / k, 3);
        ans += std::pow((n + k / 2) / k, 3);
    }else{
        ans = std::pow(n / k, 3);
    }

    std::cout << ans << std::endl;

    return 0;
}