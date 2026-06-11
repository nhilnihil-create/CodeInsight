#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

int main(int argc, char **argv)
{
    long long N, Z, W;
    std::cin >> N >> Z >> W;
    std::vector<long long> a(N);

    for(int i = 0; i < N; i++){
        std::cin >> a.at(i);
    }

    if(N == 1){
        std::cout << std::abs(a.at(0) - W) << std::endl;
        return 0;
    }else{
        long long v = std::abs(a.at(N-1) - W);
        long long w = std::abs(a.at(N-2) - a.at(N-1));
        std::cout << std::max(v, w) << std::endl;
        return 0;
    }
    
}
