#include <bits/stdc++.h>

int main() {
    long long n, ret = 0, d = 1000000000000, flg = true;
    std::cin >> n;
    std::vector<long long> a(n), b(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i] >> b[i];
        ret += a[i];
        if (a[i] > b[i] && d > b[i]) d = b[i];
        flg &= (a[i] == b[i]);
    }

    std::cout << (flg ? 0 : ret - d) << std::endl;

    return 0;
}