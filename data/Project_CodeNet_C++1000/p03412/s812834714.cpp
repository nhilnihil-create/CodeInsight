// https://beta.atcoder.jp/contests/arc092/submissions/2242272
#include <iostream>
#pragma GCC target ("tune=native,arch=ivybridge")
#pragma GCC optimize ("Ofast,unroll-loops")

int as[202020];
int bs[202020];
constexpr int block = 6000;
using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &as[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &bs[i]);
    }

    int ans = 0;
    for (int i = 0; i < n; i += block) {
        int end = min(n, i + block);
        int j = 0;
        for (; j + 3 < n; j += 4) {
            for (int ii = i; ii < end; ++ii) {
                ans ^= as[j] + bs[ii];
                ans ^= as[j + 1] + bs[ii];
                ans ^= as[j + 2] + bs[ii];
                ans ^= as[j + 3] + bs[ii];
            }
        }
        for (; j < n; ++j) {
            for (int ii = i; ii < end; ++ii) {
                ans ^= as[j] + bs[ii];
            }
        }
    }
    cout << ans << endl;

    return 0;
}
