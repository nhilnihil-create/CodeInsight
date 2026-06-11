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

int main(int argc, char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int x, y, z;
    cin >> x >> y >> z;

    int K;
    cin >> K;
    vector<long long> A(x);
    vector<long long> B(y);
    vector<long long> C(z);
    for (int i = 0; i < x; ++i) {
        cin >> A[i];
    }
    for (int i = 0; i < y; ++i) {
        cin >> B[i];
    }
    for (int i = 0; i < z; ++i) {
        cin >> C[i];
    }

    if (A.size() > B.size()) {
        swap(A, B);
    }
    if (A.size() > C.size()) {
        swap(A, C);
    }
    if (B.size() > C.size()) {
        swap(B, C);
    }
    int n = A.size();
    int m = B.size();
    int l = C.size();

    vector<long long> sums;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            sums.push_back(A[i] + B[j]);
        }
    }
    sort(sums.begin(), sums.end(), greater<long long>());
    if (sums.size() > K) {
        sums.resize(K);
    }
    sort(C.begin(), C.end());

    auto count = [&](long long S) {
        int n = C.size();
        int m = sums.size();

        long long res = 0;
        for (int i = 0, j = 0; i < n; ++i) {
            while (j < m && C[i] + sums[j] >= S) {
                ++j;
            }
            res += j;
        }
        // cout << S << " " << res << endl;
        return res;
    };

    auto find = [&](long long K, long long L, long long R) -> long long {
        long long lo = L, hi = R;
        while (lo < hi) {
            auto mi = (lo + hi + 1) >> 1;
            if (count(mi) >= K) {
                lo = mi;
            } else {
                hi = mi - 1;
            }
        }
        return lo;
    };

    long long ans = 1LL << 40;
    // long long MX = 1LL << 32;
    for (int i = 1; i <= K; ++i) {
        ans = find(i, 0, ans);
        cout << ans << '\n';
    }


    return 0;
}