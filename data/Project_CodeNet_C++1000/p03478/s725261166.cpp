#include <iostream>

int func(int a, int b, int c){
    int ans= 0;
    int sum = c;
    while(c > 0){
        ans += c % 10;
        c /= 10;
    }
    if (a <= ans && ans <= b) return sum;
    return 0;
}

int main () {
    int n, a, b, c, ans = 0;
    std::cin >> n >> a >> b;
    
    for(int i = 0; i <= n; ++i) {
        ans += func(a, b, i);
    }
    std::cout << ans << std::endl;
}