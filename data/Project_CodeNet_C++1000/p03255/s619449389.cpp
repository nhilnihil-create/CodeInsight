#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
const long long INF = 1LL << 60;    // 1.15x10^18
template<class T> void add(T &a, T b) { a = (a > INF - b ? INF : a + b); }

int main() {
    int n; cin >> n;
    long long x; cin >> x;
    vector<int> a(n);
    for (auto &ai: a) cin >> ai;
    vector<long long> acc(n + 1);
    for (int i = 0; i < n; i++) acc[i + 1] = acc[i] + a[i];
    long long mi = INF;
    for (int k = 1; k <= n; k++) {
        long long tmp = 5 * acc.back() + (k + n) * x;
        int cur = n - k;
        while (cur > k) add(tmp, 2 * acc[cur -= k]);
        mi = min(mi, tmp);
    }
    cout << mi << endl;
    return 0;
}
