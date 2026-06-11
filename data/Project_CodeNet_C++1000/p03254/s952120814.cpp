#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int N, x;
    std::cin >> N >> x;

    std::vector<int> a(N);
    for (int i = 0; i < N; i++) {
        std::cin >> a[i];
    }

    std::sort(a.begin(), a.end());

    int count = 0;
    int sum = 0;
    int i;
    for (i = 0; i < N - 1; i++) {
        if (sum + a[i] > x) {
            break;
        }

        sum += a[i];
        count++;
    }

    if (i == N - 1 && sum + a[i] == x) {
        count++;
    }

    std::cout << count << std::endl;
    
    return 0;
}