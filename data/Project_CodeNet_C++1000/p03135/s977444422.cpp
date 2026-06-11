#include <iostream>
#include <algorithm>
#include <cmath>
#include <map>
#include <numeric>
#include <queue>
#include <string>
#include <vector>
#include <iomanip>

int main(){
    int t, x;
    std::cin >> t >> x;

    std::cout << std::fixed << std::setprecision(15) << (double)t / x << std::endl;

    return 0;
}