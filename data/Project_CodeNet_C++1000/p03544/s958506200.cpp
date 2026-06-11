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
#define rep(i,n) for(int i=0; i<(n); i++)
using ll = long long;
#define fast_io(); std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);

int main(){
    int n; std::cin >> n;
    std::vector<ll> l(n+1,0);
    l[0] = 2;
    l[1] = 1;
    for(int i=2; i<n+1; i++){
        l[i] = l[i-1] + l[i-2];
    }
    std::cout << l[n] << "\n";
    return 0;
}