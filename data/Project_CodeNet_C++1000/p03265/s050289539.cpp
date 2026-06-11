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
    int x1,y1,x2,y2; std::cin>>x1>>y1>>x2>>y2;
    int x3 = x2+(-y2+y1);
    int y3 = y2+( x2-x1);
    int x4 = x3+(-y3+y2);
    int y4 = y3+( x3-x2);
    std::cout << x3 << " " << y3 << " " << x4 << " " << y4 << "\n";
    return 0;
}
