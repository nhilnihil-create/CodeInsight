#include <bits/stdc++.h>
using namespace std;

set<int> divisor(int n) {
    set<int> ret;
    for (auto i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            ret.insert(i);
            if (n % (n / i) == 0) ret.insert(n / i);
        }
    }
    return ret;
}
int main() {
    int64_t n, m, ans = 1;
    cin >> n >> m;
    auto s = divisor(m);
    for (auto itr = s.rbegin(); itr != s.rend(); itr++) {
        if (m < n * *itr) continue;
        ans = *itr;
        break;
    }
    cout << ans << endl;
    return 0;
}