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

int cowin(int k, int n){
    int ret = 0;
    while(k>n){
        n*=2; ret++;
    }
    return ret;
}

int main(){
    int n,k; std::cin >> n >> k;

    if(n>=k){
        double ans = (n-k+1)/static_cast<double>(n);
        for(int i=1; i<=k-1; i++){
            int tn = cowin(k, i);
            ans += pow(0.5, tn)/static_cast<double>(n);
        }
        std::cout << std::fixed << std::setprecision(10) << ans << "\n";
    }else{
        double ans = 0;
        for(int i=1; i<=n; i++){
            int tn = cowin(k, i);
            ans += pow(0.5, tn)/static_cast<double>(n);
        }
        std::cout << std::fixed << std::setprecision(10) << ans << "\n";
    }
    return 0;
}
