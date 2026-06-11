#include <algorithm>
#include <array>
#include <cmath>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <tuple>
#include <utility>
#include <vector>
#include <cassert>

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> x(N);

    rep(i, N) {
        cin >> x[i];
    }

    int64_t ret = 0x7FFFFFFFFFFFFFFF;
    rep(i, N-K+1) {
        int64_t l = x[i];
        int64_t r = x[i+K-1];

        int64_t time1 = abs(l) + abs(r-l);
        int64_t time2 = abs(r) + abs(r-l);
        ret = min(ret, min(time1, time2));
    }
    cout <<ret << endl;

    return 0;
}

