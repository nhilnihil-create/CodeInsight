#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>

int main(void){
    std::string S;
    int N, ans=1000;
    std::cin >> S;

    N = S.size();

    for (int i=0; i<N-2; ++i){
        int tmp = std::stoi(S.substr(i, 3));
        ans = std::min(ans, abs(tmp - 753));
    }

    std::cout << ans << std::endl;

    return 0;
}
