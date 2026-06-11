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

int main(){
    std::vector<int> a(5);
    int last=0, buf=10;
    for(int i=0; i<5; i++){
        std::cin >> a[i];
        if(a[i]%10<buf && a[i]%10!=0){
            buf = a[i]%10;
            last = i;
        }
    }

    int ans = 0;
    for(int i=0; i<5; i++){
        if(i==last){
            ans += a[i];
        }else{
            if(a[i]%10){
                ans += a[i] + 10 - a[i]%10;
            }else{
                ans += a[i];
            }
        }
    }

    std::cout << ans << "\n";
    return 0;
}
