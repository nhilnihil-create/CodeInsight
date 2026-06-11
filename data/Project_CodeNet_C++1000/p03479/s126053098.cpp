#include <iostream>

int main(int argc, char **argv)
{
    long long X, Y;
    std::cin >> X >> Y;
    long long ans = 0;
    for(;;){
        if(X > Y) break;
        ans++;
        X *= 2;
    }
    std::cout << ans << std::endl;
}
