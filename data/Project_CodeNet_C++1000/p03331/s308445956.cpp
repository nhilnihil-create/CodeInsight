#include <iostream>
#include <string>
int digitSum(int x) {
    int s = 0;
    while (x > 0) {
        s += x % 10;
        x /= 10;
    }
    return s;
}
int main() {
    int n;
    std::cin >> n;
    int ans = 1001001001;
    for (int a = 1; a < n; ++a)
        ans = std::min(ans, digitSum(a) + digitSum(n - a));
    std::cout << ans << '\n';
}