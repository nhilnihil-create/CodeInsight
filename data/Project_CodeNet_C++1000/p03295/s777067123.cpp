#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>
#include <functional>
#include <bitset>
#include <numeric>
#include <complex>
#include <iomanip>
#include <cassert>
#include <random>


#line 1 "lib/segment_tree.hpp"



#include <vector>
#include <algorithm>
#include <functional>

template<typename Monoid>
class SegmentTree {
public:
    using Operator = std::function<Monoid(Monoid, Monoid)>;

    SegmentTree(int n, const Operator &op, const Monoid init)
        : op(op), init(init) {

        num = 1;
        while (num < n) num *= 2;
        dat.resize(2 * num, init);
    }

    SegmentTree(const std::vector<Monoid> &m,
        const Operator &op, const Monoid init)
        : SegmentTree(m.size(), op, init) {

        int n = m.size();
        for (int i = 0; i < n; i++) {
            dat[num - 1 + i] = m[i];
        }
        for (int i = num - 2; i >= 0; i--) {
            dat[i] = op(dat[2 * i + 1], dat[2 * i + 2]);
        }
    }

    // Update the k-th value (0-indexed) to a.
    void update(int k, Monoid a) {
        k += num - 1;
        dat[k] = a;
        while (k > 0) {
            k = (k - 1) / 2;
            dat[k] = op(dat[2 * k + 1], dat[2 * k + 2]);
        }
    }

    // Get the value of the range [a, b).
    // k: The index of the node.
    // [left, right): The range corresponds to the k-th node.
    // Call like getval(a, b).
    Monoid getval(int a, int b, int k = 0, int left = 0, int right = -1) {
        if (right < 0) right = num;
        if (right <= a || b <= left) return init;
        if (a <= left && right <= b) return dat[k];
        Monoid vleft = getval(
            a, b, 2 * k + 1, left, left + (right - left) / 2);
        Monoid vright = getval(
            a, b, 2 * k + 2, left + (right - left) / 2, right);
        return op(vleft, vright);
    }

private:
    int num;
    std::vector<Monoid> dat;
    const Operator op;
    const Monoid init;
};

// Example: Range-Minimum Point-Update Segment Tree
SegmentTree<int> make_rmpu_segment_tree(const std::vector<int> &init) {
    const int INF = 1e9 + 2;
    auto op = [](int a, int b) { return std::min(a, b); };
    return SegmentTree<int>(init, op, INF);
}


int main() {
    int n, m; std::cin >> n >> m;
    std::vector<int> a(m), b(m), id(m);
    for (int i = 0; i < m; i++) std::cin >> a[i] >> b[i];
    std::iota(id.begin(), id.end(), 0);
    std::sort(id.begin(), id.end(), [&](int i, int j) {
        return b[i] < b[j];
    });
    SegmentTree<int> seg(n + 2, [](int i, int j) {return i && j; }, 1);
    int ans = 0;
    for (int i : id) {
        int r = seg.getval(a[i] + 1, b[i] + 1);
        ans += r;
        if (r) seg.update(b[i], 0);
    }
    std::cout << ans << std::endl;
    return 0;
}