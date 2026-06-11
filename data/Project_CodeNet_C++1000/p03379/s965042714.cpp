#include <iostream>
#include <vector>

int main() {
    int n; std::cin >> n;
    std::vector<int> v(n);
    std::vector<int> sv(n);

    for (int i = 0; i < n; i++) {
        std::cin >> v[i];
        sv[i] = v[i];
    }

    std::sort(sv.begin(), sv.end());
    int l = sv[n/2-1];
    int r = sv[n/2];

    for (int i = 0; i < n; i++) {
        std::cout << ((v[i] <= l)?r:l) << std::endl;
    }
    return 0;
}