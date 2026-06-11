#include <iostream>
#include <map>

int main() {
    int n; std::cin >> n;
    std::map<int, int> m;
    for (int i = 0; i < n; i ++) {
        int a; std::cin >> a;
        m[a]++;
    }

    unsigned long long res = 0ull;
    for (const auto mm: m) {
        if (mm.first > mm.second) {
            res += mm.second;
        } else {
            res += (mm.second - mm.first);
        }
    }

    std::cout << res << std::endl;
    return 0;
}