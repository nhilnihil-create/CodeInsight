#include <iostream>
#include <vector>

int main() {
    int N;
    std::cin >> N;
    std::vector<double> x(N);
    std::vector<std::string> u(N);
    for (int i = 0; i < N; ++i) std::cin >> x[i] >> u[i];
    
    double ans = 0;
    for (int i = 0; i < N; ++i) {
        if (u[i] == "JPY") ans += x[i];
        else ans += x[i] * 380000;
    }
    std::cout << ans << std::endl;
    return 0;
}
