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

    vector<int> ord(D, 0);
    iota(ord.begin(), ord.end(), 0);

    long long res = 1LL << 50;
    do {
        long long ans = 0;
        long long rem = G;
        for (auto x : ord) {
            long long sc = 100 * (x + 1);
            long long cnt = min((long long)P[x], (rem + sc - 1) / sc);
            ans += cnt;
            rem -= cnt * sc;
            if (cnt == P[x]) {
                rem -= C[x];
            }
            rem = max(0LL, rem);

            if (rem == 0) {
                break;
            }
        }

        res = min(res, ans);

    } while (next_permutation(ord.begin(), ord.end()));

    cout << res << '\n';
    return 0;
}