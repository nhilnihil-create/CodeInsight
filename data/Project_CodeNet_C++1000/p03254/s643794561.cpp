#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <numeric>
#include <cstdint>
#include <iomanip>
using ll = long long;

int main(){
    ll N,x; std::cin>>N>>x;
    std::vector<ll> a;
    for(int i=0; i<N; ++i){
        ll b; std::cin>>b; a.push_back(b);
    }

    std::sort(a.begin(),a.end());

    ll cnt=0;
    for(int i=0; i<N; ++i){
        x -= a[i];
        if(x<0){
            std::cout << cnt;
            return 0;
        }
        ++cnt;
    }
    if(x>0){
        std::cout << cnt - 1;
    }else{
        std::cout << cnt;
    }
    return 0;
}
