#include <iostream>
#include <vector>

int main(void){
    int N, M, ans=0;
    std::cin >> N >> M;
    std::vector<int> imos(N + 2, 0);

    for (int i=0; i<M; ++i){
        int l, r;
        std::cin >> l >> r;
        ++imos[l];
        --imos[r + 1];
    }

    for (int i=1; i<N+2; ++i){
        imos[i] += imos[i - 1];
        if (imos[i] == M && i != N + 1) ++ans;

    }

    std::cout << ans << std::endl;

    return 0;
}
