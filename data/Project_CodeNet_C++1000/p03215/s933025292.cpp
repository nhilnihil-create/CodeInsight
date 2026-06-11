#include <algorithm>
#include <cassert>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

using namespace std;
using ll = long long;

constexpr ll infl = 10000000000000007LL;
constexpr int inf = 1000000007;

int main() {
    int n, k;
    cin >> n >> k;
    vector<ll> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        a[i] += a[i - 1];
    }
    vector<ll> sums;
    vector<int> dcnt(64);
    for (int i = 1; i <= n; ++i) {
        for (int j = i; j <= n; ++j) {
            ll sum = a[j] - a[i - 1];
            sums.push_back(sum);
            for (int l = 0; l < 64; ++l) {
                dcnt[l] += sum >> l & 1;
            }
        }
    }

    ll ans = 0;
    for (int i = 63; i >= 0; --i) {
        if (dcnt[i] >= k) {
            ans |= 1LL << i;
            for (int j = 0; j < sums.size(); ++j) {
                if ((sums[j] >> i & 1) ^ 1) {
                    for (int l = 0; l < 64; ++l) {
                        dcnt[l] -= sums[j] >> l & 1;
                    }
                    sums[j] = 0;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}