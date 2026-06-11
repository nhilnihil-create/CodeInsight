#include<iostream>

int main () {
    int a, b;
    std::cin >> a >> b;

    int ans;
    if (a <= 5)
    {
        ans = 0;
    }
    else if (a <= 12)
    {
        ans = b / 2;
    } else {
        ans = b;
    }

        std::cout << ans << std::endl;
}