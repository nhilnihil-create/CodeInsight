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
using ll = long long;
#define fast_io(); std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);

int chumon_jikan(const std::vector<int>& v, int n){
    int ret = 0;

    for(int i=0; i<n-1; i++){
        ret += v[i];
        if(ret%10){
            ret += 10 - ret%10;
        }
    }
    ret += v[n-1];
    return ret;
}

int main(){
    std::vector<int> a(5);
    for(int i=0; i<5; i++){
        std::cin >> a[i];
    }
    std::sort(a.begin(),a.end());

    int ans = 1145141919;
    do{
        ans = std::min(chumon_jikan(a,5), ans);
    }while(std::next_permutation(a.begin(),a.end()));

    std::cout << ans << "\n";
    return 0;
}
