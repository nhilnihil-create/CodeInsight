#include <iostream>
#include <vector>
#include <algorithm>

int main(void){
    int N, M, ans = 0;
    std::cin >> N;
    std::vector<std::string> S(N);
    for (int i = 0; i < N; ++i){
        std::cin >> S.at(i);
    }
    std::cin >> M;
    std::vector<std::string> T(M);
    for (int i = 0; i < M; ++i){
        std::cin >> T.at(i);
    }

    for (int i = 0; i < N; ++i){
        int tmp = 0;
        for (int j = 0; j < N; ++j){
            if (S.at(i) == S.at(j)) ++tmp;
        }
        for (int j = 0; j < M; ++j){
            if (S.at(i) == T.at(j)) --tmp;
        }
        ans = std::max(ans, tmp);
    }

    std::cout << ans << std::endl;

    return 0;
}
