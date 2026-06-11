#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
using namespace std;
int MSB1(long long x) { int d = 0; while ((1LL << d) <= x) d++; return d; }

int main() {
    int n; cin >> n;
    vector<int> a(n);
    for (auto &ai: a) cin >> ai;
    multiset<int> se(a.begin(), a.end());
    int cnt = 0;
    while (!se.empty()) {
        int cur = *se.rbegin(); se.erase(--se.end());
        int rem = (1 << MSB1(cur)) - cur;
        auto it = se.find(rem);
        if (it == se.end()) continue;
        cnt++, se.erase(it);
    }
    cout << cnt << endl;
    return 0;
}
