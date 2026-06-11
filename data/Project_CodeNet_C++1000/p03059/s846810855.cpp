#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <map>

int main(){
    int a, b, t;
    std::cin >> a >> b >> t;
    
    std::cout << b * (t / a) << std::endl;

    return 0;
}