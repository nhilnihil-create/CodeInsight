#include <iostream>
#include <vector>
#include <algorithm>

int main(void){
    int N, K, ans=1e9+1;
    std::cin >> N >> K;
    std::vector<int> H(N);
    for (int i=0; i<N; ++i){
        std::cin >> H.at(i);
    }

    std::sort(H.begin(), H.end());

    for (int i=0; i<N-K+1; ++i){
        ans = std::min(ans, H.at(i + K - 1) - H.at(i));
    }

    std::cout << ans << std::endl;

    return 0;
}
