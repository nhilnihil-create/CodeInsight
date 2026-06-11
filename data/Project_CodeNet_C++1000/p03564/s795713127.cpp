#include <iostream>
#include <algorithm>
int main() {
    int N, K;
    std::cin >> N >> K;
    int ans = 1;
    for (int i = 0; i < N; i++) {
        ans = std::min(ans * 2, ans + K);
    }
    std::cout << ans << std::endl;
}