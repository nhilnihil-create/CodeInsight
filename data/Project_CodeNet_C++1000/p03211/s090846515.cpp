#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <numeric>
#include <cstdint>
#include <iomanip>
using ll = long long;
#define fast_io(); std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);

int main(){
    std::string s; std::cin>>s;
    int ans=1145141919;
    for(int i=0; i<s.size()-2; i++){
        int b = abs(std::stoi(s.substr(i,3)) - 753);
        ans = std::min(ans, b);
    }
    std::cout << ans << "\n";
    return 0;
}
