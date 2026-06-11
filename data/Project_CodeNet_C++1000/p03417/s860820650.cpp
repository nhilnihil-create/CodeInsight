#include<iostream>
#include<vector>
#include<string>

using ll = long long;

int main(){
    ll n, m;
    std::cin >> n >> m;

    if(n >= 2 && m >= 2){
        std::cout << (n - 2) * (m - 2) << std::endl;
        return 0;
    }

    if(n == 1 && m == 1){
        std::cout << 1 << std::endl;
        return 0;
    }

    if(n == 1 && m >= 2){
        std::cout << m - 2 << std::endl;
        return 0;
    }

    if(n >= 2 && m == 1){
        std::cout << n - 2 << std::endl;
        return 0;
    }
    
    return 0;
}
