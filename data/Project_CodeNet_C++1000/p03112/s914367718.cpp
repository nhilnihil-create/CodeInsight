#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
using namespace std;
static const int64_t INF = 1e18;
int main() {
    int A, B, Q;
    cin >> A >> B >> Q;
    deque<int64_t> s(A), t(B), x(Q);
    for (auto& i : s) cin >> i;
    for (auto& i : t) cin >>i;
    s.push_back(INF);
    s.push_front(-INF);
    t.push_back(INF);
    t.push_front(-INF);
    for (auto& i : x) {
        cin >> i;
        auto b = lower_bound(s.begin(), s.end(), i);
        auto d = lower_bound(t.begin(), t.end(), i);
        auto ans = INF;
        for (auto j : {*(b - 1), *b}) {
            for (auto k : {*(d - 1), *d}) {
                auto m = min(abs(j - i) + abs(k - j), abs(k - i) + abs(j - k));
                if (m < ans) ans = m;
            }
        }
        cout << ans << endl;
    }
}