#include <iostream>
#include <vector>

int main(void){
    int N, M, ans=0;
    std::cin >> N >> M;
    std::vector<int> food(M, 0);

    for (int i=0; i<N; ++i){
        int K;
        std::cin >> K;
        for (int j=0; j<K; ++j){
            int a;
            std::cin >> a;
            ++food.at(a - 1);
        }
    }

    for (int i=0; i<M; ++i){
        if (food.at(i) == N) ++ans;
    }

    std::cout << ans << std::endl;

    return 0;
}
