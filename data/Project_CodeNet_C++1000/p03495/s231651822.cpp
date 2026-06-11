#include <iostream>
#include <algorithm>

int main () {
    int n, k, x=0;
    std::cin >> n >> k;
    int a, check[200000] ={0};
    for(int i = 0; i < n; i++){
        std::cin >> a;
        check[a] += 1;
    }
    for(int i = 0; i < 200000; ++i){
        if(check[i] != 0) ++x;
    }
    std::sort(check, check + 200000);
    int ans = 0;
    for(int i = 0; i < x - k; ++i){
        if(check[i] == 0){
            ++x;
            continue;
        }
        ans += check[i];
    }
    std::cout << ans << std::endl;
}