#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

int main() {
    int n;
    std::cin >> n;

    std::vector<long long> a(n + 1);
    a[0] = 2;
    a[1] = 1;
    for (int i = 2; i <= n; i++) {
        a[i] = a[i - 1] + a[i - 2];
    }

    std::cout << a[n] << "\n";
}