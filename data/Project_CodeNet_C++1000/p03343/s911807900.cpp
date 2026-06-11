#include <iostream>
#include <vector>
#include <algorithm>

constexpr int INF = (1 << 30);

int main() {
    int n, k, q;
    std::cin >> n >> k >> q;
    std::vector<int> a(n + 1, -INF);
    for (int i = 0; i < n; i++) std::cin >> a[i];

    auto f = [&] (int x) -> int {
        std::vector<int> buff, dat;
        for (const int &e : a) {
            if (e >= x) {
                buff.push_back(e);
            } else {
                std::sort(buff.begin(), buff.end());
                const int _size = int(buff.size());
                for (int i = 0; i + k <= _size; i++) {
                    dat.push_back(buff[i]);
                }
                buff.clear();
            }
        }
        std::sort(dat.begin(), dat.end());
        if (dat.size() < q) return INF;
        return (dat[q - 1] - dat[0]);
    };


    int min = INF;
    for (const int &x : a) {
        min = std::min(min, f(x));
    }

    std::cout << min << '\n';

    return 0;
}