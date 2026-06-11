#include <iostream>
#include <cmath>
#include <string>

int main(void){
    std::string S;
    int N, ans=1000;
    std::cin >> S;

    N = S.size();

    for (int i=0; i<N-2; ++i){
        std::string s = "";
        s += S[i];
        s += S[i + 1];
        s += S[i + 2];
        int tmp = std::stoi(s);
        if (ans > abs(tmp - 753)){
            ans = abs(tmp - 753);
        }
    }

    std::cout << ans << std::endl;

    return 0;
}
