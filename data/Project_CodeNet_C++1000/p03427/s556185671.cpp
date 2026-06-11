#include <iostream>

int main(){
    long long n;
    std::cin >> n;
    auto f = [&](long long a){
        int res = 0;
        while(a){
            res += a % 10;
            a /= 10;
        }
        return res;
    };
    int ans = f(n);
    long long k = 1;
    while(n >= 10){
        n /= 10;
        k *= 10;
    }
    ans = std::max(ans, f(n * k - 1));
    std::cout << ans << std::endl;
}