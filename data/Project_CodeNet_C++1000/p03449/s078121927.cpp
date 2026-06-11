#include <iostream>
#include <vector>
#include <algorithm>

int main(void){
    int N, ans=0;
    std::cin >> N;
    std::vector<std::vector<int>> A(2, std::vector<int>(N));

    for (int i=0; i<2; ++i){
        for (int j=0; j<N; ++j){
            std::cin >> A.at(i).at(j);
        }
    }

    for (int i=1; i<N; ++i){
        A.at(0).at(i) += A.at(0).at(i - 1);
        A.at(1).at(N - i - 1) += A.at(1).at(N - i);
    }

    for (int i=0; i<N; ++i){
        ans = std::max(ans, A.at(0).at(i) + A.at(1).at(i));
    }

    std::cout << ans << std::endl;

    return 0;
}
