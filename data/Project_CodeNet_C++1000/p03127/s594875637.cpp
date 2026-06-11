#include <iostream>
#include <numeric>

int main(){
    int n;
    std::cin >> n;

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int a;
        std::cin >> a;
        ans = std::gcd(ans, a);
    }
    
    std::cout << ans << std::endl;

    return 0;
}