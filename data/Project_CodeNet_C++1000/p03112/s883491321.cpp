#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <bitset>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <numeric>
#include <iostream>
#include <iomanip>
#include <string>
#include <chrono>
#include <random>
#include <cmath>
#include <cassert>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <functional>
#include <sstream>

using namespace std;

class Solution {
public:

};

int main(int argc, char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, q;
    cin >> n >> m >> q;
    vector<long long> A(n);
    vector<long long> B(m);
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }
    sort(A.begin(), A.end());
    for (int i = 0; i < m; ++i) {
        cin >> B[i];
    }
    sort(B.begin(), B.end());

    const long long INF = 1LL << 60;
    vector<long long> da(n, INF);
    vector<long long> db(m, INF);
    for (int i = 0; i < n; ++i) {
        auto it = lower_bound(B.begin(), B.end(), A[i]);
        if (it != B.end()) {
            da[i] = min(da[i], *it - A[i]);
        }
        if (it != B.begin()) {
            --it;
            da[i] = min(da[i], A[i] - *it);
        }
    }
    for (int i = 0; i < m; ++i) {
        auto it = lower_bound(A.begin(), A.end(), B[i]);
        if (it != A.end()) {
            db[i] = min(db[i], *it - B[i]);
        }
        if (it != A.begin()) {
            --it;
            db[i] = min(db[i], B[i] - *it);
        }
    }
    while (q-- > 0) {
        long long x;
        cin >> x;

        long long res = INF;
        {
            auto it = lower_bound(A.begin(), A.end(), x);
            int idx = it - A.begin();
            if (idx < n) {
                long long ans = A[idx] - x + da[idx];
                res = min(res, ans);
            }
            if (idx > 0) {
                long long ans = x - A[idx - 1] + da[idx - 1];
                res = min(res, ans);
            }
        }
        {
            auto it = lower_bound(B.begin(), B.end(), x);
            int idx = it - B.begin();
            if (idx < m) {
                long long ans = B[idx] - x + db[idx];
                res = min(res, ans);
            }
            if (idx > 0) {
                long long ans = x - B[idx - 1] + db[idx - 1];
                res = min(res, ans);
            }
        }

        cout << res << "\n";
    }

    return 0;
}