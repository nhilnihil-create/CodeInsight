#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <numeric>
#include <cstdint>
#include <iomanip>
#include <set>
#include <map>
#include <unordered_map>
#include <cassert>
#include <queue>
#define rep(i,n) for(int i=0; i<(n); i++)
using ll = long long;
#define fast_io(); std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);

int main(){
    ll n,y;
    std::cin >> n >> y;
    for(int i=0; i<=n; i++){
        for(int j=0; j<=n-i; j++){
            int k = n-i-j;
            if(10000*i+5000*j+1000*k==y){
                std::cout << i << " " << j << " " << k << "\n";
                return 0;
            }
        }
    }
    std::cout << "-1 -1 -1\n";
    return 0;
}