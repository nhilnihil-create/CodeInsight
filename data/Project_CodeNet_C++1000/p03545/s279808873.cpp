#include <iostream>

int main(void){
    std::string S, ans="";
    std::cin >> S;
    bool flg = false;
    for (int i = -1; i < 2; i += 2){
        for (int j = -1; j < 2; j += 2){
            for (int k = -1; k < 2; k += 2){
                int a = S.at(0) - '0';
                int b = S.at(1) - '0';
                int c = S.at(2) - '0';
                int d = S.at(3) - '0';
                if (a + b * i + c * j + d * k == 7){
                    ans += std::to_string(a);
                    if (i < 0) ans += '-';
                    else ans += '+';
                    ans += std::to_string(b);
                    if (j < 0) ans += '-';
                    else ans += '+';
                    ans += std::to_string(c);
                    if (k < 0) ans += '-';
                    else ans += '+';
                    ans += std::to_string(d) + "=7";
                    flg = true;
                    break;
                }
            }
            if (flg) break;
        }
        if (flg) break;
    }

    std::cout << ans << std::endl;

    return 0;
}
