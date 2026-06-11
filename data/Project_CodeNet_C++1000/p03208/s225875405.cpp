#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <map>

int main(){
    long long N, K; std::cin >> N >> K;
    std::vector<long long> h(N);
    for (auto& r : h)std::cin >> r;
    std::sort(h.begin(), h.end());
    long long ans = 10000000000;
    for (int i = 0; i + K - 1 < N; ++i) 
        ans = std::min(ans, h[i + K - 1] - h[i]);
    std::cout << ans << std::endl;

    return 0;
}