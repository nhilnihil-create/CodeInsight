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
    ll N; std::cin >> N;
    std::vector<ll> t, x, y;
    t.push_back(0); x.push_back(0); y.push_back(0);
    for(int i=0; i<N; i++){
        ll b1, b2, b3; std::cin >> b1 >> b2 >> b3;
        t.push_back(b1); x.push_back(b2); y.push_back(b3);
    }

    bool flag=true;
    for(int i=0; i<t.size()-1; i++){
        ll dt=t[i+1]-t[i], dx=abs(x[i+1]-x[i]), dy=abs(y[i+1]-y[i]);
        if(dt<dx+dy || dt%2!=(dx+dy)%2){
            flag=false;
        }
    }

    if(flag){
        std::cout << "Yes";
    }else{
        std::cout << "No";
    }
    return 0;
}
