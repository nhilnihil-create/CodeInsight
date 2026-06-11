#include <iostream>
#include <string>
#include <vector>

int main()
{
    long long n, m; std::cin >> n >> m;

    long long ans;
    if(n > m) {
        std::swap(n,m);
    }
    
    if(n == 1) {
        ans = abs(m - 2);
    }else if( n == 2) {
        ans = 0;
    } else {
        ans = (n-2)*abs((m-2));
    }

    std::cout << ans << std::endl;
}