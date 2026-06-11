#include <iostream>
#include <vector>
#include <algorithm>

int main(void){
    int N, ans=0;
    std::cin >> N;
    std::vector<int> a(N);

    for (int i=0; i<N; ++i){
        std::cin >> a.at(i);
    }

    std::sort(a.begin(), a.end(), std::greater<int>());

    for (int i=0; i<N; ++i){
        if (i % 2 == 0) ans += a.at(i);
        else ans -= a.at(i);
    }

    std::cout << ans << std::endl;

    return 0;
}