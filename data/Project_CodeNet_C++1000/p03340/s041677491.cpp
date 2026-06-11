#include <iostream>
#include <vector>

int main() {
    int n; std::cin >> n;
    std::vector<unsigned int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    std::vector<int>  t(n);
    unsigned int k = 0;

    for (int i = 0; i < n; i++) {
        int h = 0;
        if (i != 0) {
            h = t[i-1];
            k ^= a[i-1];
        }
        while (h < n && (k & a[h]) == 0) {
            k ^= a[h];
            h++;
        }
        t[i] = h;
    }

    unsigned long long c = 0;
    for (int i = 0; i < n; i++) {
        c += t[i] - i;
    }
    std::cout << c << std::endl;

    return 0;
}