#include<iostream>
#include<algorithm>

int main(){

    size_t k, a, b;
    std::cin >> k >> a >> b;

    if(k >= 2 && a + 2 < b){
        size_t ans = a;
        k -= a - 1;
        if(k % 2 == 1) ans++, k--;

        ans += (b - a) * (k / 2);

        std::cout << ans << std::endl;
    }else{
        std::cout << k + 1 << std::endl;
    }

    return 0;
}
