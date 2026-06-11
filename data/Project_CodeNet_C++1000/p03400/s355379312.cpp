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
    ll n, d, x; std::cin >> n >> d >> x;
    std::vector<ll> a;
    for(int i=0; i<n; i++){
        ll b; std::cin >> b; a.push_back(b);
    }

    std::vector<ll> ch(d+1,0);
    for(auto &ai : a){
        for(int i=0; i*ai+1<=d; i++){
            ch[i*ai+1]++;
        }
    }

    std::cout << x + std::accumulate(ch.begin(), ch.end(), 0LL);
    return 0;
}
