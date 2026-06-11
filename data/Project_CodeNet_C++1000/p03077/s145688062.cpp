#include<iostream>
#include<vector>
#include<string>

// ref : https://img.atcoder.jp/abc123/editorial.pdf
using ll = long long;

int main(){
    ll n, cap[5];
    std::cin >> n;
    ll minCap = 1e15;
    for(int i = 0; i < 5; i++){
        std::cin >> cap[i];
        minCap = std::min(minCap, cap[i]);
    }

    ll ans = 4; // (i - 1) + (5 - 1)
    if(n % minCap == 0) ans += n / minCap;
    else ans += n / minCap + 1;

    std::cout << ans << std::endl;
    
    return 0;
}
