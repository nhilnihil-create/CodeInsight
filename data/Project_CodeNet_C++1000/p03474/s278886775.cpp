#include <iostream>

int main(void){
    int A, B;
    std::string S, ans="Yes";
    std::cin >> A >> B >> S;

    for (int i=0; i<A+B+1; ++i){
        if (i != A && S.at(i) == '-'){
            ans = "No";
            break;
        } else if (i == A && S.at(i) != '-') {
            ans = "No";
            break;
        }
    }

    std::cout << ans << std::endl;
    
    return 0;
}
