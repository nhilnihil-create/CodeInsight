#include <iostream>
#include <numeric>

int main(){
    int n, x;
    std::cin >> n >> x;

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int x_;
        std::cin >> x_;
        x_ = abs(x - x_);
        ans = std::gcd(ans, x_);
    }

    std::cout << ans << std::endl;

    return 0;
}