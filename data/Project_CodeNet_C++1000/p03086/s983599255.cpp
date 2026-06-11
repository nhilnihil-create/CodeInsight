#include <iostream>

int main(void){
    int ans=0, tmp=0;
    std::string S;
    std::cin >> S;

    for (char c: S){
        if (c == 'A' || c == 'T' || c == 'G' || c == 'C'){
            ++tmp;
        } else {
            if (tmp != 0 && tmp > ans){
                ans = tmp;
                tmp = 0;
            }
        }
    }
    
    if (tmp != 0 && tmp > ans) ans = tmp;

    std::cout << ans << std::endl;

    return 0;
}
