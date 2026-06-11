#include <iostream>

int main(){
    int a, b;
    std::cin >> a >> b;
    int c = 0;

    if (a > b)
    {
        c += a;
        a--;
    }
    else
    {
        c += b;
        b--;
    }
    if (a > b)
    {
        c += a;
        a--;
    }
    else
    {
        c += b;
        b--;
    }
    std::cout << c << std::endl;

    return 0;
}