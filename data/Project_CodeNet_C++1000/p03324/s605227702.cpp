#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <climits>
int main()
{
    long D,N;
    std::cin >> D >> N;
    long m=std::pow(100,D);
    if(N==100){
        N++;
    }
    std::cout << N*m << std::endl;
    return 0;
}