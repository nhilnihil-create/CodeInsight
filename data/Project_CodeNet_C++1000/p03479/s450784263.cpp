#include<iostream>
#include<vector>
#include<string>

using ll = long long;

int main(){
    ll x, y;
    std::cin >> x >> y;
    if(x > y) std::swap(x, y);
    ll cnt = 0;
    ll val = x;
    while(val <= y){
        cnt++;
        val += val;
    }
    std::cout << cnt << std::endl;
    return 0;
}
