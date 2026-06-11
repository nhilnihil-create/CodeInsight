#include <iostream>
#include <string>

int main(void){
    int A, B, ans=0;
    std::cin >> A >> B;

    for (int i=A; i<=B; ++i){
        std::string S = std::to_string(i);
        if (S.at(0) == S.at(4) && S.at(1) == S.at(3)) ++ans;
    }

    std::cout << ans << std::endl;

    return 0;
}
