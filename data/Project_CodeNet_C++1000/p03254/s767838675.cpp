#include <iostream>
#include <vector>

int main() {
    int n, x; std::cin >> n >> x;
    std::vector<int> v(n);
    for (int i = 0; i < n; i++) {
        std::cin >> v[i];
    }
    std::sort(v.begin(), v.end());
    int cnt = 0;
    int i = 0;
    for (; i < n; i++) {
        if (x <v[i]) {
            break;
        }
        x -= v[i];
        cnt++;
    }
    if (i >= n && x > 0) {
        cnt--;
    }
    std::cout << cnt << std::endl;
    return 0;
}