#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <numeric>
#include <cstdint>
#include <iomanip>
#include <set>
using ll = long long;
#define fast_io(); std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);

int main(){
    fast_io();

    int n,m; std::cin >> n >> m;
    int max_l=0, min_r=1145141919;
    for(int i=0; i<m; i++){
        int l,r; std::cin >> l >> r;
        max_l = std::max(max_l, l);
        min_r = std::min(min_r, r);
    }

    std::cout << std::max(min_r-max_l+1,0) << "\n";
    return 0;
}
