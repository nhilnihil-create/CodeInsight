#include <iostream>
#include <algorithm>

int main () {
    int a[110]={1000}, n;
    std::cin >> n;
    for(int i = 0; i < n; ++i){
        std::cin >> a[i];
    }
    std::sort(a, a+n, std::greater<int>());
    int ans = 0, op = 1;
    for(int i = 0; i < n; ++i){
        ans += op*a[i];
        op *= -1;
    }
    std::cout << ans << std::endl;
}