#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <tuple>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <cmath>
#include <iomanip>
#include <functional>
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define REP(i, n) for (int i = 1; i < (int)(n); ++i)
using namespace std;
using lint = int64_t;

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> A(N);
    rep(i, N) cin >> A[i];
    vector<lint> sum(N + 1, 0);
    rep(i, N) sum[i + 1] = sum[i] + A[i];
    map<lint, int> mp;
    lint ans = 0;
    rep(i, N + 1) {
        ans += mp[sum[i] % M];
        ++mp[sum[i] % M];
    }
    cout << ans << "\n";
    return 0;
}
