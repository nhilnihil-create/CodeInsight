#include<iostream>
#include<vector>
#include<string>

using ll = long long;

int main(){
    int n;
    std::cin >> n;
    ll cnt = 0;
    for(int i = 0; i < n; i++){
        ll a;
        std::cin >> a;
        while(a % 2 == 0){
            cnt++;
            a /= 2;
        }
    }

    std::cout << cnt << std::endl;
    return 0;
}
