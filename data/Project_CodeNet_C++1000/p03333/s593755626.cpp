#include <bits/stdc++.h>

int main() {
    long long n, retl = 0, retr = 0;
    std::cin >> n;
    std::vector<long long> l(n), r(n);
    std::multiset<std::tuple<long long, long long, long long>> mr;
    std::multiset<std::tuple<long long, long long, long long>, std::greater<>> ml;
    for (auto i = 0ll; i < n; i++) {
        std::cin >> l[i] >> r[i];
        ml.emplace(l[i], r[i], i);
        mr.emplace(r[i], l[i], i);
    }

    auto pos = 0ll;
    // when i is odd, go left; go right otherwise
    for (auto i = 0ll; i < n; i++) {
        long long lp, rp, index;
        if (i % 2) {
            auto curr = *mr.begin();
            rp = std::get<0>(curr), lp = std::get<1>(curr), index = std::get<2>(curr);
            if (rp < pos) {
                retl += pos - rp;
                pos = rp;
            }
        } else {
            auto curr = *ml.begin();
            lp = std::get<0>(curr), rp = std::get<1>(curr), index = std::get<2>(curr);
            if (pos < lp) {
                retl += lp - pos;
                pos = lp;
            }
        }
        mr.erase(mr.find(std::make_tuple(rp, lp, index)));
        ml.erase(ml.find(std::make_tuple(lp, rp, index)));
    }
    retl += (pos < 0 ? -pos : pos);

    for (auto i = 0ll; i < n; i++) {
        ml.emplace(l[i], r[i], i);
        mr.emplace(r[i], l[i], i);
    }

    pos = 0;
    for (auto i = 0ll; i < n; i++) {
        long long lp, rp, index;
        if (i % 2 == 0) {
            auto curr = *mr.begin();
            rp = std::get<0>(curr), lp = std::get<1>(curr), index = std::get<2>(curr);
            if (rp < pos) {
                retr += pos - rp;
                pos = rp;
            }
        } else {
            auto curr = *ml.begin();
            lp = std::get<0>(curr), rp = std::get<1>(curr), index = std::get<2>(curr);
            if (pos < lp) {
                retr += lp - pos;
                pos = lp;
            }
        }
        mr.erase(mr.find(std::make_tuple(rp, lp, index)));
        ml.erase(ml.find(std::make_tuple(lp, rp, index)));
    }
    retr += (pos < 0 ? -pos : pos);

    std::cout << std::max(retl, retr) << std::endl;

    return 0;
}