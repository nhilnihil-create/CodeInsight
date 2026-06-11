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
    int n,m,k; std::cin >> n >> m;
    std::vector<int> tabemono(m+1,0);
    rep(i,n){
        std::cin >> k;
        int aij;
        rep(j,k){
            std::cin >> aij;
            tabemono[aij]++;
        }
    }

    int ans = 0;
    rep(i,m+1){
        if(tabemono[i]==n) ans++;
    }

    std::cout << ans << "\n";
    return 0;
}