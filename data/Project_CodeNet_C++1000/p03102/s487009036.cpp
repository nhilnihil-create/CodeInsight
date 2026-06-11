#include <iostream>
#include <vector>

int main() {
    int n, m, c;

    std::cin >> n >> m >> c;
    
    std::vector<int> b(m);
    for (int i = 0; i < m; i++) {
        std::cin >> b[i];
    }

    int count = 0;
    for (int j = 0; j < n; j++) {
        int sum = 0;
        for (int i = 0; i < m; i++) {
            int a;
            std::cin >> a;
            sum += a * b[i];
        }
        if (sum + c > 0) {
            count++;
        }
    }

    std::cout << count << std::endl;

    return 0;
}