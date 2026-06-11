#include <iostream>
#include <vector>
#include <map>

int main() {
    int n; std::cin >> n;
    std::map<int, int> l, r;
    for (int i = 0; i < n; i++) {
        int v; std::cin >> v;
        auto& c = (i%2)?l:r;
        c[v]++;
    }

    std::vector<std::pair<int, int>>L, R;
    for (const auto& ll: l) {
        L.push_back(std::make_pair(ll.first, ll.second));
    }
    for (const auto& rr: r) {
        R.push_back(std::make_pair(rr.first, rr.second));
    }
    std::sort(L.begin(), L.end(), [](const auto& x, const auto& y){return x.second > y.second;});
    std::sort(R.begin(), R.end(), [](const auto& x, const auto& y){return x.second > y.second;});

    int rrr = R[0].second, lll = L[0].second;

    if (L[0].first == R[0].first) {
        if (L.size() == 1 && R.size() == 1) {
            rrr = 0;
        } else if (L.size() == 1) {
            rrr = R[1].second;
        } else if (R.size() == 1) {
            lll = L[1].second;
        } else {
            if (L[1].second < R[1].second) {
                rrr = R[1].second;
            } else {
                lll = L[1].second;
            }
        }
    }

    std::cout << n / 2 - lll + n / 2 - rrr << std::endl;
    return 0;
}