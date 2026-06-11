#include <iostream>

int main()
{
    int sss;
    std::cin >> sss;

    int s_1=sss/100, s_2=(sss-100*s_1)/10, s_3=(sss-100*s_1-10*s_2);
    int ans = s_1 + s_2 + s_3;

    std::cout << ans << std::endl;
}