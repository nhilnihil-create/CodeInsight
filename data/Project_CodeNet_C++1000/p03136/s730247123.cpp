#include <iostream>

int main()
{
    int n; std::cin >> n;
    int s = 0; int m = 0;
    for (int i = 0; i < n; i++) {
        int a; std::cin >> a;
        s+=a;
        m = std::max(m, a);
    }
    std::cout << ((s-m>m)?"Yes":"No") << std::endl;
    return 0;
}
