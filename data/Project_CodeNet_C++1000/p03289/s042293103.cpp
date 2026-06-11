#include <iostream>

int main(void){
    std::string S, ans="AC";
    bool c_flg=false;
    std::cin >> S;

    if (S.at(0) != 'A'){
        ans = "WA";
    } else {
        for (int i=1; i<S.size(); ++i){
            if (std::isupper(S.at(i))){
                if (1 < i && i < S.size() - 1){
                    if (S.at(i) == 'C' && not(c_flg)){
                        c_flg = true;
                    } else {
                        ans = "WA";
                    }
                } else {
                    ans = "WA";
                    break;
                }
            }
        }
    }
    if (not(c_flg)) ans = "WA";

    std::cout << ans << std::endl;

    return 0;
}
