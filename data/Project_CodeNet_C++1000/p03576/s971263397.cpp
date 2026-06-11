#include <iostream>
#include <vector>

static bool canhold(
    const std::vector<std::pair<long long, long long>>& Ps,
    long long xr,
    long long xl,
    long long yb,
    long long yt,
    int k
)
{
    int cnt = 0;
    for (auto& p: Ps) {
        if (xr <= p.first && p.first <= xl && yb <= p.second && p.second <= yt) {
            cnt++;
        }
    }
    return cnt >= k;
}

int main() {
    int n, k; std::cin >> n >> k;
    std::vector<std::pair<long long, long long>> Ps(n);

    for (int i = 0; i < n; i++) {
        int x, y; std::cin>> x >> y;
        Ps[i].first = x; Ps[i].second = y;
    }

    long long m = 2e9 * 2e9;

    for (int xr = 0; xr < n; xr++) {
        for (int xl = xr + 1; xl < n; xl++) {
            for (int yb = 0; yb < n; yb++) {
                for (int yt = yb + 1; yt < n; yt++) {
                    auto XR = std::min(Ps[xr].first, Ps[xl].first);
                    auto XL = std::max(Ps[xr].first, Ps[xl].first);
                    auto YB = std::min(Ps[yb].second, Ps[yt].second);
                    auto YT = std::max(Ps[yb].second, Ps[yt].second);

                    auto M = (YT - YB) * (XL - XR);

                    if (M >= m) {
                        continue;
                    }

                    if (!canhold(Ps, XR, XL, YB, YT, k)) {
                        continue;
                    }

                    m = std::min(m, M);
                }
            }
        }
    }

    std::cout << m << std::endl;

    return 0;
}