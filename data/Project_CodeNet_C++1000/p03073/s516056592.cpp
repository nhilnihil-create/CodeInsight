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
    std::string s; std::cin >> s;

    int ans = 0;
    for(int i=0; i<s.size(); i++){
        if(i%2==0 && s[i]!=s[0]) ans++;
        if(i%2!=0 && s[i]==s[0]) ans++;
    }
    std::cout << ans << "\n";
    return 0;
}
