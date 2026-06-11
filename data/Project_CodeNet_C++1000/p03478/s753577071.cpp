#include <iostream>
#include <string>

int main(void){
    int N, A, B, ans=0;
    std::cin >> N >> A >> B;

    for (int i=1; i<=N; ++i){
        std::string S = std::to_string(i);
        int a = 0;
        for (char s: S){
            a += (int)(s - '0');
        }
        if (A <= a && a <= B){
            ans += i;
        }
    }

    std::cout << ans << std::endl;

    return 0;
}
