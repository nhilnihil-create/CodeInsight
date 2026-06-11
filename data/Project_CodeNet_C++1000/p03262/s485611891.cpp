#include <iostream>
#include <vector>

int gcd(int a, int b)
{
    if (b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}

int main()
{
    int n, x; std::cin >> n >> x;
    std::vector<int> a(n, 0);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        a[i] = std::abs(a[i] - x);
    }

    int gg = a[0];

    for (int i = 1; i < n; i++) {
        gg = gcd(gg, a[i]);
    }

    std::cout << gg << std::endl;

    return 0;
}
