#include <iostream>
#include <vector>

int main() {
    int n, h; std::cin >> n >> h;
    std::vector<std::pair<int, int>> st_t(n);
    int max_a = 0;
    for (int i = 0; i < n; i++) {
        std::cin >> st_t[i].first >> st_t[i].second;
        max_a = std::max(max_a, st_t[i].first);
    }

    std::sort(st_t.begin(), st_t.end(), [](const auto &a, const auto &b){
        return a.second> b.second;
    });

    int thr = 0;
    for (const auto& t: st_t) {
        if (t.second > max_a) {
            thr++;
            h -= t.second;
            if (h <= 0) {
                break;
            }
        } else {
            break;
        }
    }
    if (h > 0) {
        thr += (h + max_a - 1)/ max_a;
    }
    std::cout << thr << std::endl;
    return 0;
}
