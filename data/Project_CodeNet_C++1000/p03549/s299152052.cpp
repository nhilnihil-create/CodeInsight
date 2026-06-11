#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>

int main() {
    int n, m;
    std::cin >> n >> m;

    int t1 = 1900*m;
    int t2 = 100*(n-m);
    int tsum = t1 + t2;

    // 2700 / 4 + 2*2700 *(3/16) * 3*2700 *(9/64)
    //公比　3/4  1 - 1/(2*2)
    // 一ずつ増える 

    std::cout << tsum * (int)(std::pow(2, m)) << std::endl;
}