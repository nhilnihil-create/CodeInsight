#include <iostream>
long long xor_0_to_n(long long n)
{
    if (n < 0) return 0;
    switch (n % 4) {
        case 0:
            return n;
        case 1:
            return 1;
        case 2:
            return n + 1;
        case 3:
            return 0;
    }
}
int main()
{
    long long a, b;
    std::cin >> a >> b;
    std::cout << (xor_0_to_n(a - 1) ^ xor_0_to_n(b)) << std::endl;
}
