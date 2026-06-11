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

    int D, G;
    cin >> D >> G;
    vector<int> P(D);
    vector<int> C(D);
    for (int i = 0; i < D; ++i) {
        cin >> P[i] >> C[i];
    }

    long long res = 1LL << 50;

    int N = 1 << D;

    for (int i = 0; i < N; ++i) {
        long long ans = 0;
        long long rem = G;

        for (int j = 0; j < D; ++j) {
            if (i & (1 << j)) {
                ans += P[j];
                rem -= P[j] * (100LL * (j + 1LL));
                rem -= C[j];
            }
        }

        if (rem > 0) {
            for (int j = D - 1; j >= 0; --j) {
                if (i & (1 << j)) {
                    continue;
                }
                long long sc = 100 * (j + 1);
                long long cnt = (rem + sc - 1) / sc;
                cnt = min(cnt, (long long)P[j]);
                ans += cnt;
                rem -= cnt * sc;
                if (rem <= 0) {
                    break;
                }
            }
        }

        if (rem <= 0) {
            res = min(res, ans);
        }
    }

    cout << res << '\n';
    return 0;
}