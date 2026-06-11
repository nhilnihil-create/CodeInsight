#include <iostream>

int main(void){
    std::string S;
    int N;
    char ans = '1';
    long long tmp = -1, K;
    std::cin >> S >> K;
    N = S.size();
    for (int i = 0; i < N; ++i){
        if (S.at(i) != '1'){
            ans = S.at(i);
            break;
        } else {
            tmp = i;
        }
    }

    if (K - 1 <= tmp) {
        ans = '1';
    }

    std::cout << ans << std::endl;

    return 0;
}
