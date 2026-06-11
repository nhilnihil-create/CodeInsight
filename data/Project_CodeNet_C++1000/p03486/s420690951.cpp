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
    std::string s,t;
    std::cin >> s >> t;

    std::sort(s.begin(), s.end());
    std::sort(t.begin(), t.end(), std::greater<int>());

    /*
    rep(i,s.size()){
        if(s[i]<t[i]){
            std::cout << "Yes" << "\n";
            return 0;
        }
    }
    if(s[s.size()-1]==t[s.size()-1] && s.size()<t.size()){
        std::cout << "Yes" << "\n";
        return 0;
    }
    std::cout << "No" << "\n";
    */
    if(s<t) std::cout << "Yes" << "\n";
    else std::cout << "No" << "\n";

    return 0;
}
