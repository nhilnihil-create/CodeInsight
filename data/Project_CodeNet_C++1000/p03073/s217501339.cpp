#include <iostream>
#include <algorithm>

int main(void){
    std::string S;
    int b=0, w=0, ans;
    std::cin >> S;

    for (int i=0; i<S.size(); ++i){
        if (i % 2 == 0){
            if (S.at(i) == '0') ++b;
            else ++w;
        } else {
            if (S.at(i) == '0') ++w;
            else ++b;
        }
    }

    ans = std::min(b, w);

    std::cout << ans << std::endl;

    return 0;
}
