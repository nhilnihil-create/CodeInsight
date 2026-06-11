#include <iostream>

int main(){
    int A, B, C, ans;
    std::cin >> A >> B >> C;

    ans = B / A;
    if(ans > C){
        ans = C;
    }

    std::cout << ans << std::endl;

    return 0;
}
