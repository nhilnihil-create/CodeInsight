#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <climits>
int main()
{
    long N,K;
    std::cin >> N >> K;
    long x[100000+1];
    for(long i=1; i<=N; i++){
        std::cin >> x[i];
    } 

    std::vector<long> time;
    for(long i=1; i<=N-K+1;i++){
        long left=i;
        long right=i+K-1;
        time.push_back(std::min(abs(x[left]),abs(x[right]))+x[right]-x[left]);
    }
    std::sort(time.begin(),time.end());
    std::cout << time[0] << std::endl;
    return 0;
}