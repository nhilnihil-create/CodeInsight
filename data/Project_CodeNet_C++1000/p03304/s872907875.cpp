#include <iostream>
using ll = long long;
int main() {
    ll n, m, d;
    std::cin >> n >> m >> d;
    ll k = (d == 0 ? n : (n - d) * 2);
    ll a = k * (m - 1);
    ll b = n * n;
    printf("%.10lf\n", (double)a / b);
}