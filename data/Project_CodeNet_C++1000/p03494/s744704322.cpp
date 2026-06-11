#include <iostream>


int divide (int a, int ans) {
    int count = 0;
    for(int i = 0; a != 0; ++i){
        if(a % 2 == 0){
            a = a / 2;
            ++count;
        } else break;
    }
    if(ans > count) return count;
    return ans;
}

int main () {
    int n, ans = 10000000;
    std::cin >> n;
    int a[n];
    
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
        ans = divide(a[i], ans);
    }
    
    std::cout << ans << std::endl;
}