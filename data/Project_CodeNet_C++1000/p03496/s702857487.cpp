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
    int N;
    cin >> N;
    vector<int> a(N);
    rep(i, N) cin >> a[i];
    
    cout << 2 * (N - 1) << "\n";
    vector<pair<int, int>> S(N);
    rep(i, N) S[i] = pair<int, int>{abs(a[i]), i};
    sort(S.rbegin(), S.rend());
    rep(i, N) {
        if (i == S[0].second) continue;
        cout << S[0].second + 1 << " " << i + 1 << "\n";
    }
    if (a[S[0].second] > 0) {
        rep(i, N - 1) cout << i + 1 << " " << i + 2 << "\n";
    } else {
        for (int i = N - 1; i >= 1; --i) cout << i + 1 << " " << i << "\n";
    }
    return 0;
}
