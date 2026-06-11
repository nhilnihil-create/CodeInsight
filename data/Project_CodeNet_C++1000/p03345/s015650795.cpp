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
using ll = long long;
#define fast_io(); std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);

int main(){
    ll a,b,c,k; std::cin >> a >> b >> c >> k;
    std::cout << (( k%2 )?( b-a ):( a-b )) << "\n";
    return 0;
}
