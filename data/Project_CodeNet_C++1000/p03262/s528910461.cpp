#include<iostream>
#include<vector>
#include<string>

using ll = long long;

long long gcd(long long a, long long b) {
    if (b == 0) return a;
    else return gcd(b, a % b);
}

int main(){
    ll n, start;
    std::cin >> n >> start;
    ll ans;
    std::cin >> ans;
    ans = std::abs(ans - start);
    for(int i = 1; i < n; i++){
        ll x;
        std::cin >> x;
        x = std::abs(x - start);
        if(x == 0) continue;
        ans = gcd(ans, x);
    } 

    std::cout << ans << std::endl;
    return 0;
}
