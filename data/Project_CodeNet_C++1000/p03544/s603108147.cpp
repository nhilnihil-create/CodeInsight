#include <iostream>

int main(void){
    int N;
    long long a, b=1, c=2, ans;
    std::cin >> N;

    if (N == 1) ans = 1;
    else {
        for (int i=2; i<=N; ++i){
            a = b + c;
            c = b;
            b = a;
        }
        ans = a;
    }

    std::cout << ans << std::endl;

    return 0;
}
