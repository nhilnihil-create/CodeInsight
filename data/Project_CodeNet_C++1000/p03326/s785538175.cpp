#include <bits/stdc++.h>

struct Data {
    int64_t x;
    int64_t y;
    int64_t z;
};

int main() {
    int N, M;
    std::cin >> N >> M;
std::vector<Data> vals;
    int64_t x, y, z;
    for (int i = 0; i < N; ++i) {
        std::cin >> x >> y >> z;
        vals.push_back({x, y, z});
    }

    int64_t max = INT32_MIN;
    for (int i = 0; i < (1 << 3); ++i) {
        int flags[3];
        flags[0] = (i >> 0) & 1;
        flags[1] = (i >> 1) & 1;
        flags[2] = (i >> 2) & 1;

        std::vector<Data> buf = vals;

        std::sort(buf.begin(), buf.end(), [&](const auto& l, const auto& r) {
            int64_t lsum = 0, rsum = 0;
            if (flags[0]) {
                lsum += l.x;
                rsum += r.x;
            } else {
                lsum -= l.x;
                rsum -= r.x;
            }

            if (flags[1]) {
                lsum += l.y;
                rsum += r.y;
            } else {
                lsum -= l.y;
                rsum -= r.y;
            }

            if (flags[2]) {
                lsum += l.z;
                rsum += r.z;
            } else {
                lsum -= l.z;
                rsum -= r.z;
            }

            return lsum < rsum;
        });

        int64_t x_sum = 0, y_sum = 0, z_sum = 0;
        for (int j = 0; j < M; ++j) {
            x_sum += buf[j].x;
            y_sum += buf[j].y;
            z_sum += buf[j].z;
        } 

        max = std::max(max, (std::abs(x_sum) + std::abs(y_sum) + std::abs(z_sum)));  
    }

    std::cout << max << std::endl;

    return 0;
}
